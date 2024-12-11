import numpy as np
import cv2
import matplotlib.pyplot as plt
from scipy.signal import find_peaks, fftconvolve

def calculate_mtf(image, edge_roi):
    """
    Calculates the Modulation Transfer Function (MTF) of an optical system using a slanted edge.
    Args:
        image: 2D numpy array of the image with a slanted edge.
        edge_roi: Coordinates of the region of interest (ROI) as (x, y, width, height).
    
    Returns:
        spatial_frequencies: The spatial frequencies.
        mtf: The corresponding MTF values.
    """
    # Extract the region of interest (ROI) containing the slanted edge
    x, y, width, height = edge_roi
    roi = image[y:y + height, x:x + width]
    
    # Sum along rows to generate the Edge Spread Function (ESF)
    esf = np.mean(roi, axis=0)
    
    # Compute the Line Spread Function (LSF) by differentiating the ESF
    lsf = np.diff(esf)
    
    # Normalize the LSF
    lsf /= np.max(lsf)
    
    # Perform the Fourier Transform of the LSF
    mtf = np.abs(np.fft.fft(lsf))
    
    # Normalize the MTF
    mtf /= np.max(mtf)
    
    # Generate spatial frequencies
    spatial_frequencies = np.fft.fftfreq(len(mtf), d=1.0)
    spatial_frequencies = spatial_frequencies[:len(mtf) // 2]
    mtf = mtf[:len(mtf) // 2]
    
    return spatial_frequencies, mtf

def plot_mtf(spatial_frequencies, mtf):
    """
    Plots the Modulation Transfer Function (MTF).
    """
    plt.figure(figsize=(8, 5))
    plt.plot(spatial_frequencies, mtf, label='MTF')
    plt.xlabel('Spatial Frequency (cycles/pixel)')
    plt.ylabel('Modulation Transfer Function')
    plt.title('MTF Curve')
    plt.grid()
    plt.legend()
    plt.show()

# Example usage
if __name__ == "__main__":
    # Load an image (ensure it's grayscale)
    image_path = "slanted_edge.jpg"  # Replace with your image path
    image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    
    if image is None:
        print("Error: Image not found. Check the path.")
        exit(1)
    
    # Define the region of interest (ROI) containing the slanted edge
    edge_roi = (50, 50, 300, 50)  # Adjust the values based on your image
    
    # Calculate MTF
    spatial_frequencies, mtf = calculate_mtf(image, edge_roi)
    
    # Plot the MTF
    plot_mtf(spatial_frequencies, mtf)
