string fn(vector<char>& arr) {
    return string(arr.begin(), arr.end())
}

{% comment %} In JavaScript, benchmarking shows that concatenation with += is faster than using .join(). {% endcomment %}