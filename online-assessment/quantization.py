import torch
import torch_tensorrt
from ultralytics import YOLO
from torch_tensorrt import Input

# Load YOLOv8 model
model = YOLO('yolov8n.pt')  # Replace with your trained model path
model = model.model.eval()  # Set to eval mode

# Create a calibration dataset
calibration_data = [torch.randn(1, 3, 640, 640) for _ in range(100)]  # Replace with actual images

# Define calibration DataLoader
class CalibrationDataset(torch.utils.data.Dataset):
    def __init__(self, data):
        self.data = data

    def __len__(self):
        return len(self.data)

    def __getitem__(self, idx):
        return self.data[idx]

calibration_loader = torch.utils.data.DataLoader(
    CalibrationDataset(calibration_data), batch_size=1, shuffle=False
)

# Compile the model using PyTorch TensorRT with INT8 precision
model_trt = torch_tensorrt.compile(
    model,
    inputs=[Input((1, 3, 640, 640), dtype=torch.float32)],  # Match YOLO input size
    enabled_precisions={torch.int8},  # Use INT8 precision
    calibrator=torch_tensorrt.ptq.DataLoaderCalibrator(
        calibration_loader,
        cache_file="calibration_cache.txt",  # Saves calibration info
        use_cache=False,
        algo_type=torch_tensorrt.ptq.CalibrationAlgo.MINMAX_CALIBRATION  # Can be adjusted as needed
    )
)

# Run inference with the quantized model
input_tensor = torch.randn(1, 3, 640, 640)  # Replace with actual test image
output = model_trt(input_tensor)

print(output)
