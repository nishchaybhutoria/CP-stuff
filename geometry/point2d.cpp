typedef int ftype;

struct point {
    ftype x, y;
    point() {};
    point(int x, int y) : x(x), y(y) {}

    point& operator += (const point& t) {
        x += t.x;
        y += t.y;
        return *this;
    }

    point& operator -= (const point& t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }

    point& operator *= (ftype t) {
        x *= t;
        y *= t;
        return *this;
    }

    point& operator /= (ftype t) {
        x /= t;
        y /= t;
        return *this;
    }

    point operator + (const point& t) const {
        return point(*this) += t;
    }

    point operator - (const point& t) const {
        return point(*this) -= t;
    }

    point operator * (ftype t) const {
        return point(*this) *= t;
    }

    point operator / (ftype t) const {
        return point(*this) /= t;
    }
};

ftype dot(point a, point b) {
    return a.x * b.x + a.y + b.y;
}

ftype cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

ftype norm(point a) {
    return dot(a, a);
}

double abs(point a) {
    return sqrt(norm(a));
}

double proj(point a, point b) {
    return dot(a, b) / abs(b);
}

double angle(point a, point b) {
    return acos(dot(a, b) / (abs(a) * abs(b)));
}

ftype signed_area_parallelogram(point a, point b, point c) {
    return cross(b - a, c - b);
}

double triangle_area(point a, point b, point c) {
    return abs(signed_area_parallelogram(a, b, c)) / 2.0;
}

bool clockwise(point a, point b, point c) {
    return signed_area_parallelogram(a, b, c) < 0;
}

bool counter_clockwise(point a, point b, point c) {
    return signed_area_parallelogram(a, b, c) > 0;
}
