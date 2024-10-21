int fn(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0, ans = 0;

    while (i < arr1.size() && j < arr2.size()) {
        // do some logic here
        if (CONDITION) {
            i++;
        } else {
            j++;
        }
    }

    while (i < arr1.size()) {
        // do logic
        i++;
    }

    while (j < arr2.size()) {
        // do logic
        j++;
    }

    return ans;
}