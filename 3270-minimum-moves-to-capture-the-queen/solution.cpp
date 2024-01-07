class Solution {
private:
    bool isOdd(int i) {
        return i % 2 != 0;
    }
    bool isBlack(int i, int j) {
        return isOdd(i) != isOdd(j);
    }

    bool isInSameDiagonalBishop(int a, int b, int c, int d, int e, int f) {
        if((c + d == e + f && !(c + d == a + b && a > min(c , e) && a < max(c, e))) or (c - d == e - f && !(c - d == a - b && a > min(c , e) && a < max(c, e)))) {
            return true;
        }  else {
            return false;
        }
    }

    bool isInSameDiagonalRook(int a, int b, int c, int d, int e, int f) {
        return (a == e && !(a == c && d > min(b,f) && d < max(b,f)));
    }
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // in case of bishop if its not in same col of queen its not possible to capture

        if(isInSameDiagonalRook(a, b, c, d, e, f)) {
            return 1;
        }

        if(isInSameDiagonalRook(b, a, d, c, f, e)) {
            return 1;
        }
        
        if(isBlack(c, d) == isBlack(e, f)) {
            if(isInSameDiagonalBishop(a, b, c, d, e, f)) {
                return 1;
            }
        }

        return 2;
    }
};
