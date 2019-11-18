class RLEIterator {
private:
    vector<int> rle;
    int i, q;
public:
    RLEIterator(vector<int>& A) {
        this->rle = A;
        i = 0; q = 0;
    }
    
    int next(int n) {
        while (i < rle.size()) {
            if (q + n > rle[i]) {
                n -= rle[i] - q;
                i += 2;
                q = 0;
            } else {
                q += n;
                return rle[i + 1];
            }
         }
         return -1;
    }
};
