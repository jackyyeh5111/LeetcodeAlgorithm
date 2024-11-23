#include <iostream>
#include <cmath>

// Vector structure for 3D vectors
struct Vector3 {
    float x, y, z;

    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    // Dot product of two vectors
    float dot(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Normalize the vector to have a magnitude of 1
    Vector3 normalize() const {
        float magnitude = std::sqrt(x * x + y * y + z * z);
        return Vector3(x / magnitude, y / magnitude, z / magnitude);
    }
};

// Lambertian shading function
float lambertianShading(const Vector3& surfaceNormal, const Vector3& lightDirection, float lightIntensity) {
    // Ensure both vectors are normalized
    Vector3 normalizedNormal = surfaceNormal.normalize();
    Vector3 normalizedLightDir = lightDirection.normalize();

    // Compute the dot product
    float dotProduct = normalizedNormal.dot(normalizedLightDir);

    // Clamp the dot product to the range [0, 1]
    float clampedDot = std::max(0.0f, dotProduct);

    // Return the diffuse shading value
    return lightIntensity * clampedDot;
}

int main() {
    // Surface normal
    Vector3 surfaceNormal(0, 0, 1);  // A surface facing along the z-axis

    // Light direction
    Vector3 lightDirection(1, 1, -1);  // A light coming from the top-right

    // Light intensity
    float lightIntensity = 1.0f;

    // Compute Lambertian shading
    float shading = lambertianShading(surfaceNormal, lightDirection, lightIntensity);

    // Output the result
    std::cout << "Lambertian shading result: " << shading << std::endl;

    return 0;
}
