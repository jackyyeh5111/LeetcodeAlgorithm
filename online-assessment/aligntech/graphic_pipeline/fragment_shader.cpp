#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Define a simple 3D vector and color structure
struct Vec3 {
    float x, y, z;
    
    // Vector subtraction
    Vec3 operator-(const Vec3& v) const {
        return Vec3{x - v.x, y - v.y, z - v.z};
    }
    
    // Dot product
    float dot(const Vec3& v) const {
        return x * v.x + y * v.y + z * v.z;
    }
    
    // Normalize the vector
    Vec3 normalize() const {
        float length = std::sqrt(x * x + y * y + z * z);
        return Vec3{x / length, y / length, z / length};
    }
};

struct Color {
    unsigned char r, g, b;
    
    // Blend two colors together
    Color operator*(float factor) const {
        return Color{
            static_cast<unsigned char>(std::min(r * factor, 255.0f)),
            static_cast<unsigned char>(std::min(g * factor, 255.0f)),
            static_cast<unsigned char>(std::min(b * factor, 255.0f))
        };
    }
};

struct Image {
    std::vector<Color> data;
    int width, height;
    
    Image(int w, int h) : width(w), height(h) {
        data.resize(w * h);
    }
    
    Color& at(int x, int y) {
        return data[y * width + x];
    }
    
    const Color& at(int x, int y) const {
        return data[y * width + x];
    }
};

// Simple lighting and texture mapping
class FragmentShader {
public:
    // Perform a simple diffuse shading calculation
    Color computeColor(const Vec3& fragPos, const Vec3& normal, const Vec3& lightPos, const Color& textureColor) {
        // Simple diffuse lighting calculation
        Vec3 lightDir = (lightPos - fragPos).normalize();
        float diffuse = std::max(normal.dot(lightDir), 0.0f); // Lambertian reflection
        
        // Return the texture color modulated by the diffuse light factor
        return textureColor * diffuse;
    }

    // Simple function to simulate a texture (just returning a color based on coordinates)
    Color sampleTexture(int x, int y, const Image& texture) {
        // Simple texture wrapping (modulo)
        int texX = x % texture.width;
        int texY = y % texture.height;
        
        return texture.at(texX, texY);
    }

    // Main fragment shader function
    void run(const Image& texture, const Vec3& lightPos, const Vec3& normal, Image& output) {
        for (int y = 0; y < output.height; ++y) {
            for (int x = 0; x < output.width; ++x) {
                // Simulate texture coordinates
                Color textureColor = sampleTexture(x, y, texture);
                
                // Simulate fragment position in 3D space (just for simplicity, assume z=0 for all fragments)
                Vec3 fragPos{(float)x, (float)y, 0.0f};
                
                // Compute the final color using diffuse shading
                Color finalColor = computeColor(fragPos, normal, lightPos, textureColor);
                
                // Set the final color to the output image
                output.at(x, y) = finalColor;
            }
        }
    }
};

int main() {
    // Define some basic parameters
    int width = 800, height = 600;
    
    // Create a dummy texture (just a color gradient for simplicity)
    Image texture(100, 100);
    for (int y = 0; y < 100; ++y) {
        for (int x = 0; x < 100; ++x) {
            texture.at(x, y) = Color{(unsigned char)(x * 2), (unsigned char)(y * 2), 0};
        }
    }
    
    // Create an output image
    Image output(width, height);
    
    // Define a light source position
    Vec3 lightPos{400.0f, 300.0f, 100.0f};
    
    // Define a surface normal (for simplicity, assume it's pointing straight up)
    Vec3 normal{0.0f, 0.0f, 1.0f};
    
    // Create a FragmentShader instance and run it
    FragmentShader shader;
    shader.run(texture, lightPos, normal, output);
    
    // Output the final image (this would be shown in a window or saved to a file in a real system)
    std::cout << "Rendered " << width << "x" << height << " image!" << std::endl;
    
    return 0;
}
