import torch
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt

# Generate synthetic data for linear regression: y = 2x + 3 + noise
torch.manual_seed(42)  # For reproducibility

class LinearRegressionModel(nn.Module):
  def __init__(self):
    super(LinearRegressionModel, self).__init__()
    self.linear = nn.Linear(1, 1)
  def forward(self, x):
    return self.linear(x)

def train(X, y):
  model = LinearRegressionModel()
  
  criterion = nn.MSELoss()
  optimizer = optim.SGD(model.parameters(), lr=0.01)
  
  num_epochs = 100
  for epoch in range(num_epochs):
    # Forward pass
    y_pred = model(X)
    
    # Compute loss
    loss = criterion(y_pred, y)
    
    # Backward pass
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()
    
      # Print loss every 10 epochs
    if (epoch + 1) % 10 == 0:
        print(f"Epoch [{epoch+1}/{num_epochs}], Loss: {loss.item():.4f}")
    
  # Print learned parameters
  print(f"Learned weight: {model.linear.weight.item():.4f}, Learned bias: {model.linear.bias.item():.4f}")

  # Plot results
  plt.scatter(X.numpy(), y.numpy(), label="Data")
  plt.plot(X.numpy(), model(X).detach().numpy(), color="red", label="Fitted Line")
  plt.legend()
  plt.show()

if __name__ == '__main__':
    X = torch.linspace(0, 10, 100).unsqueeze(1)  # Feature data
    y = 2 * X + 3 + torch.randn_like(X) * 2  # Target with noise
    train(X, y)
