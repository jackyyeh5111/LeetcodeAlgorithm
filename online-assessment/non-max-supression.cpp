#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Structure to represent a bounding box
struct BoundingBox {
    float x_min, y_min, x_max, y_max, score;
};

// Function to compute the Intersection over Union (IoU) of two boxes
float computeIoU(const BoundingBox& box1, const BoundingBox& box2) {
    float x1 = max(box1.x_min, box2.x_min);
    float y1 = max(box1.y_min, box2.y_min);
    float x2 = min(box1.x_max, box2.x_max);
    float y2 = min(box1.y_max, box2.y_max);

    float intersection = max(0.0f, x2 - x1 + 1) * max(0.0f, y2 - y1 + 1);
    float box1_area = (box1.x_max - box1.x_min + 1) * (box1.y_max - box1.y_min + 1);
    float box2_area = (box2.x_max - box2.x_min + 1) * (box2.y_max - box2.y_min + 1);
    float union_area = box1_area + box2_area - intersection;

    return intersection / union_area;
}

// Function to perform Non-Maximal Suppression
vector<BoundingBox> nonMaximalSuppression(vector<BoundingBox>& boxes, float iou_threshold) {
    // Sort boxes by score in descending order
    sort(boxes.begin(), boxes.end(), [](const BoundingBox& a, const BoundingBox& b) {
        return a.score > b.score;
    });

    vector<BoundingBox> result;

    while (!boxes.empty()) {
        // Select the box with the highest score and add it to the result
        BoundingBox current = boxes[0];
        result.push_back(current);
        boxes.erase(boxes.begin());

        // Filter out boxes with high IoU with the current box
        boxes.erase(remove_if(boxes.begin(), boxes.end(), [&](const BoundingBox& box) {
            return computeIoU(current, box) > iou_threshold;
        }), boxes.end());
    }

    return result;
}

int main() {
    vector<BoundingBox> boxes = {
        {50, 50, 150, 150, 0.9}, 
        {60, 60, 160, 160, 0.8}, 
        {200, 200, 300, 300, 0.7},
        {55, 55, 155, 155, 0.75}
    };
    float iou_threshold = 0.5;

    vector<BoundingBox> filtered_boxes = nonMaximalSuppression(boxes, iou_threshold);

    // Print filtered boxes
    for (const auto& box : filtered_boxes) {
        cout << "Box: (" << box.x_min << ", " << box.y_min << ", "
             << box.x_max << ", " << box.y_max << "), Score: " << box.score << endl;
    }

    return 0;
}
