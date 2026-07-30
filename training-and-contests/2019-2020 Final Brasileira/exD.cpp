#include <bits/stdc++.h>
using namespace std;

struct point{
    double x, y;
    int brilho;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    double operator%(point q) const {
        return x*q.y -y*q.x;
    }
};

struct Reta{
    double a, b, c;
    Reta(point p, point q){
        a = p.y-q.y;
        b = q.x-p.x;
        c = p%q;
    }

    double eval(point p) const{
        return a*p.x + b*p.y + c; 
    }

    double dist(point p) const {
        return fabs(eval(p))/hypot(a,b);
    }
};

bool cmp(point &a, point &b){
    return a.brilho < b.brilho;
}

double EPS = 1e-7;
inline int cmp2(double x, double y){
    return (x <= y+EPS) ? (x+EPS < y) ? -1 : 0 : 1;
}

point pinf = {1e7, 1e7};

int found = 2*acos(0)/EPS +20;
double bb = 2*acos(0);

double solve(double ang, vector<point> &pt){
    
    Reta r = Reta(pinf, {pinf.x+10.0*cos(ang), pinf.y + 10.0*sin(ang)});

    int d = 0;
    point pant = pt[0];

    for(int i = 1; i < pt.size(); i++){
        if(cmp2(r.dist(pt[i]), r.dist(pant)) < 0){
            Reta errada = Reta(pt[i], pant);
            double rang = acos(0) - atan(errada.b/errada.a);
            return (ang+EPS);
            if(cmp2(rang, ang) < 0){
                bb/=2;
                return ang-bb;
            }
            else{
                bb/=2;
                return ang+bb;
            }
        }
        else
            pant = pt[i];
    }
    found = 0;
    return -8848;
}

int main() {
    int n;
    cin >> n;
    vector<point> pt(n);
    for(int i = 0; i < n; i++)
        cin >> pt[i].x >> pt[i].y >> pt[i].brilho;
    sort(pt.rbegin(), pt.rend(), cmp);

    double ang = 0;
    while(found--){
        ang = solve(ang, pt);
        if(ang < -1000){
            cout << "Y\n";
            return 0;
        }
        if(found%1000 == 0)
        cout << ang*90/acos(0) << endl;
    }
    if(ang < -1000){
        cout << "Y\n";
    }
    else cout << "N\n";
    return 0;
}