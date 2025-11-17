class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1,area2,overarea,ta;
        area1=(abs(ax2-ax1))*(abs(ay2-ay1));
        area2=(abs(bx2-bx1))*(abs(by2-by1));
        if((ay1>=by2) || (by1>=ay2)){
            return area1+area2;
        }
        if((ax2<=bx1) || (bx2<=ax1)){
            return area1+area2;
        }
        else{
        overarea=(abs(min(ax2,bx2)-max(ax1,bx1)))*(abs(min(ay2,by2)-max(ay1,by1)));
        ta=area1+area2-overarea;
        return ta;
        }
    }
};