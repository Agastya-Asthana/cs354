//
// Created by Agastya Asthana on 3/1/22.
//
#include <stdio.h>

struct point{
    int x;
    int y;
};

struct rect{
    struct point pt1;
    struct point pt2;
};

void Enlarge_Rectangle(struct rect *r, struct point p);

int main(){
    struct point rect_p1 = {0, 0};
    struct point rect_p2 = {1, 1};
    struct rect sample_rect = {rect_p1, rect_p2};
    struct point encompass_point = {2, 3};
    printf("The starting Rectangle dimensions are: (%d, %d) and (%d, %d)\n\n", sample_rect.pt1.x, sample_rect.pt1.y, sample_rect.pt2.x, sample_rect.pt2.y);
    printf("Out of bound point to encompass is: (%d, %d)\n", encompass_point.x, encompass_point.y);
    Enlarge_Rectangle(&sample_rect, encompass_point);
    printf("The new rectangle dimensions are: (%d, %d) and (%d, %d)\n\n", sample_rect.pt1.x, sample_rect.pt1.y, sample_rect.pt2.x, sample_rect.pt2.y);

    struct point encompass_point2 = {-1, 1};
    printf("New out of bound point to encompass is: (%d, %d)\n", encompass_point2.x, encompass_point2.y);
    Enlarge_Rectangle(&sample_rect, encompass_point2);
    printf("The new rectangle dimensions are: (%d, %d) and (%d, %d)\n\n", sample_rect.pt1.x, sample_rect.pt1.y, sample_rect.pt2.x, sample_rect.pt2.y);

    struct point encompass_point3 = {1, 2};
    printf("New in bound point to encompass is: (%d, %d)\n", encompass_point3.x, encompass_point3.y);
    Enlarge_Rectangle(&sample_rect, encompass_point3);
    printf("The new rectangle dimensions are: (%d, %d) and (%d, %d)\n", sample_rect.pt1.x, sample_rect.pt1.y, sample_rect.pt2.x, sample_rect.pt2.y);

}

void Enlarge_Rectangle(struct rect *r, struct point p){
    //handle the x coord
    if(!(p.x > r->pt1.x && p.x < r->pt2.x)){
        if (p.x > r->pt2.x) r->pt2.x = p.x;
        else r->pt1.x = p.x;
    }
    //handle the y coord
    if(!(p.y > r->pt1.y && p.y < r->pt2.y)){
        if (p.y > r->pt2.y) r->pt2.y = p.y;
        else r->pt1.y = p.y;
    }

}