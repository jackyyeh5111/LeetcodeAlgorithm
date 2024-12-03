""" 
    data.txt
    
    0,0,0
    1,1,0
    0,1,1
    1,0,1
"""

import torch
from pathlib import Path
import numpy as np

class TrainingDataset(torch.utils.data.Dataset):
    
    def __init__(self, path: Path) -> None:
        self.data = np.loadtxt(path, delimiter=",")
        self.inputs = torch.tensor(self.data[:, :2], dtype=torch.float32)
        self.targets = torch.tensor(self.data[:, 2:], dtype=torch.float32)

    def __getitem__(self, idx: int) -> tuple[torch.Tensor, torch.Tensor]:
        return self.inputs[idx], self.targets[idx]

    def __len__(self) -> int:
        return len(self.data)

class MultiLayerPerceptron(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.mlp_a = torch.nn.Linear(2, 4)
        self.mlp_b = torch.nn.Linear(4, 1)
        self.relu = torch.nn.ReLU()

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        x = self.mlp_a(x)
        x = self.relu(x)
        x = self.mlp_b(x)
        return x       

def training_loop(
    model: torch.nn.Module, 
    dataset: torch.utils.data.Dataset,
) -> None:
    dl = torch.utils.data.DataLoader(dataset, batch_size=1, shuffle=True)

    criterion = torch.nn.MSELoss()
    optimizer = torch.optim.SGD(model.parameters(), lr=1e-2)

    model.train()
    epoch_loss: float = float("inf")
    epoch: int = 0

    while epoch_loss > 0.001 and epoch <= 1000:
        running_loss = 0.0
        for idx, (x, y) in enumerate(dl):
            optimizer.zero_grad() # reset gradient weights

            pred = model(x) # forward prediction

            loss = criterion(pred, y) # compute loss
            loss.backward() # back propogation to compute gradients
            running_loss += loss.item()

            optimizer.step() # update weights based on computed gradients

        epoch += 1
        epoch_loss = running_loss / (idx + 1)
        if epoch % 10 == 0:
            print(f"Epoch {epoch} loss: {epoch_loss}")

    assert epoch_loss <= 0.001
    assert epoch <= 1000

def infer(
    model: torch.nn.Module, 
    dataset: torch.utils.data.Dataset,
) -> None:
    dl = torch.utils.data.DataLoader(dataset, batch_size=1)

    with torch.no_grad():
        model.eval()
        for idx, (x, y) in enumerate(dl):
            pred = model(x)
            print (f'{x}: {pred.item()}')
        

if __name__ == "__main__":
    path = Path("/home/coderpad/data/data.txt")
    model = MultiLayerPerceptron()
    dataset = TrainingDataset(path)
    training_loop(model, dataset)
    infer(model, dataset)