#include <stdio.h>
typedef struct {
    double x;
    double y;
} Point;
typedef struct {
    char name[16];
    int score;
} Student;
Point moved(Point p, double dx, double dy)
{
    p.x += dx;
    p.y += dy;
    return p;
}
void move_in_place(Point *p, double dx, double dy)
{
    p->x += dx;
    p->y += dy;
}
int main(void)
{
    Point a = {1.0, 2.0};
    Point b = moved(a, 3.0, -1.0);
    printf("a=(%.1f, %.1f) b=(%.1f, %.1f)\n", a.x, a.y, b.x, b.y);
    move_in_place(&a, 3.0, -1.0);
    printf("a=(%.1f, %.1f)\n", a.x, a.y);
    Student s = {"Aki", 80};
    Student t = s;
    t.name[0] = 'M';
    printf("%s %s\n", s.name, t.name);
    return 0;
}
