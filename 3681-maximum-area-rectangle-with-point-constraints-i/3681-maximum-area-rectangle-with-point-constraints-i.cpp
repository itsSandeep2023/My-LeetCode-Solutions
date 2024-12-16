class Solution {
public:
    int calculateArea(vector<vector<int>>& corners) {
        vector<int> bottomLeft = corners[0];
        vector<int> topLeft = corners[1];
        vector<int> bottomRight = corners[2];
        vector<int> topRight = corners[3];

        if (bottomLeft[0] != topLeft[0] or bottomLeft[1] != bottomRight[1] or
            bottomRight[0] != topRight[0] or topLeft[1] != topRight[1])
            return -1;
        return abs(bottomLeft[0] - bottomRight[0]) *
               abs(bottomLeft[1] - topLeft[1]);
    }

    bool hasInternalPoints(vector<vector<int>>& points,
                           vector<vector<int>>& corners) {
        vector<int> bottomLeft = corners[0];
        vector<int> topLeft = corners[1];
        vector<int> bottomRight = corners[2];
        vector<int> topRight = corners[3];

        for (auto& point : points) {
            if (point == bottomLeft or point == bottomRight or
                point == topLeft or point == topRight)
                continue;
            int x = point[0], y = point[1];
            if (point[0] >= bottomLeft[0] and point[0] <= bottomRight[0] and
                point[1] >= bottomLeft[1] and point[1] <= topLeft[1])
                return true;
        }

        return false;
    }

    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4)
            return -1;
        int maxArea = -1;

        for (int i{0}; i < n - 3; i++) {
            for (int j{i + 1}; j < n - 2; j++) {
                for (int k{j + 1}; k < n - 1; k++) {
                    for (int l{k + 1}; l < n; l++) {
                        vector<vector<int>> corners = {points[i], points[j],
                                                       points[k], points[l]};
                        sort(corners.begin(), corners.end());
                        int area = calculateArea(corners);
                        if (area > maxArea and
                            !hasInternalPoints(points, corners))
                            maxArea = area;
                    }
                }
            }
        }

        return maxArea;
    }
};