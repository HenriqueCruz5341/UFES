#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int box;
    int n_boxes;
    int n_invi = 0;

    cin >> n_boxes;

    pair<int, int> boxes[n_boxes];

    for (int i = 0; i < n_boxes; i++) {
        cin >> boxes[i].first;
        boxes[i].second = 0;
    }

    sort(boxes, boxes + n_boxes);

    for (int i = 0; i < n_boxes; i++) {
        for (int j = i + 1; j < n_boxes; j++) {
            if (boxes[i].first < boxes[j].first && !boxes[j].second) {
                n_invi++;
                boxes[j].second = 1;
                break;
            }
        }
    }

    cout << n_boxes - n_invi << endl;

    return 0;
}