#include <graphics.h>
#include <cstdlib>
#include <cmath>

void drawLineDDA(int x1, int y1, int x2, int y2) {

    int dx = x2 - x1;
    int dy = y2 - y1;


    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    /*
     When dy>dx
     xIncrement = 1/slope
     yIncrement = 1
     When dx>dy
     xIncrement = 1
     yIncrement = slope
     */
    float xIncrement = (float) dx / (float) steps;
    float yIncrement = (float) dy / (float) steps;

    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

void drawLineBresenham(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int x = x0, y = y0;

    int xStep = (x0 < x1) ? 1 : -1;
    int yStep = (y0 < y1) ? 1 : -1;

    if (dx >= dy) {
        int p = 2 * dy - dx;
        while (x != x1) {
            putpixel(x, y, YELLOW);
            x += xStep;
            if (p >= 0) {
                y += yStep;
                p -= 2 * dx;
            }
            p += 2 * dy;
        }
    } else {
        int p = 2 * dx - dy;
        while (y != y1) {
            putpixel(x, y, YELLOW);
            y += yStep;
            if (p >= 0) {
                x += xStep;
                p -= 2 * dy;
            }
            p += 2 * dx;
        }
    }
    putpixel(x, y, YELLOW); // Draw the last pixel
}

void plotOctant(int xc ,int x, int yc, int y, int color){
    //Quad1
    putpixel(xc + y, yc - x, color);
    putpixel(xc + x, yc - y, color);

    //Quad2
    putpixel(xc - x, yc - y, color);
    putpixel(xc - y, yc - x, color);

    //Quad3
    putpixel(xc - y, yc + x, color);
    putpixel(xc - x, yc + y, color);

    //Quad4
    putpixel(xc + x, yc + y, color);
    putpixel(xc + y, yc + x, color);
}

void drawCircle(int xc, int yc, int radius) {
    int y = radius, x = 0;
    int radiusError = 1 - radius;
    while (x <= y) {
        plotOctant(xc,x,yc,y,14);
        x++;

        if (radiusError < 0)
            radiusError += 2 * x + 1;
        else {
            y--;
            radiusError += 2 * (x - y) + 1;
        }
    }
}

void drawCircleBresenham(int xc, int yc, int r) {
    int x = 0, y = r;
    int s = 3 - 2 * r;

    while (x <= y) {
        plotOctant(xc,x,yc,y,12);
        x++;
        if (s <= 0)
            s = s + 4 * x + 1;
        else {
            y--;
            s = s + 4 * (x - y) + 1;
        }
    }
}



int main() {
    int gd = DETECT, gm;
    initwindow(1600,800);

    drawLineDDA(607,690,607,500);
    drawLineDDA(607,500,651,500);
    drawLineDDA(651,500,651,371);
    drawLineDDA(651,371,691,371);
    drawLineDDA(691,371,691,260);
    drawLineDDA(691,260,728,260);
    drawLineDDA(728,260,728,167);
    drawLineDDA(728,167,760,167);
    drawLineDDA(760,167,760,106);
    drawLineDDA(760,106,790,106);
    drawLineDDA(790,106,790,197);
    drawLineDDA(790,197,817,197);
    drawLineDDA(817,197,817,325);
    drawLineDDA(817,325,853,325);
    drawLineDDA(853,325,853,432);
    drawLineDDA(853,432,892,432);
    drawLineDDA(892,432,892,530);
    drawLineDDA(892,530,930,530);
    drawLineDDA(930,530,930,690);
    drawLineDDA(930,690,607,690);


    for (int j = 530; j < 690; j+=30) {
        int i = 620;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
    }
    for (int j = 400; j < 690; j+=30) {
        int i = 661;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
    }
    for (int j = 295; j < 690; j+=30) {
        int i = 700;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
    }

    for (int j = 195; j < 690; j+=30) {
        int i = 737;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
    }
    for (int j = 227; j < 690; j+=30) {
        int i = 787;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
    }
    for (int j = 355; j < 690; j+=30) {
        int i = 822;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
    }
    for (int j = 467; j < 690; j+=30) {
        int i = 858;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
    }
    for (int j = 562; j < 690; j+=30) {
        int i = 898;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
    }
    drawLineDDA(773,690,773,106);

    // Draw the sun
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    drawCircle(200, 150, 50); // Outer circle

    setcolor(LIGHTRED);
    drawCircleBresenham(200, 150, 40); // Middle circle

    setcolor(RED);
    drawCircle(200, 150, 30); // Inner circle


    int rayLength = 60;
    for (int angle = 0; angle < 360; angle += 45) {
        int x1 = 200 + 50 * cos(angle * 3.14 / 180);
        int y1 = 150 + 50 * sin(angle * 3.14 / 180);
        int x2 = 200 + (50 + rayLength) * cos(angle * 3.14 / 180);
        int y2 = 150 + (50 + rayLength) * sin(angle * 3.14 / 180);
        drawLineBresenham(x1, y1, x2, y2);
    }

    getch();
    closegraph();
    return 0;
}
