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

void drawLineBresenham(int x0, int y0, int x1, int y1,int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int x = x0, y = y0;

    int xStep = (x0 < x1) ? 1 : -1;
    int yStep = (y0 < y1) ? 1 : -1;

    if (dx >= dy) {
        int p = 2 * dy - dx;
        while (x != x1) {
            putpixel(x, y, color);
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
            putpixel(x, y, color);
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

void drawCircle(int xc, int yc, int radius,int color) {
    int y = radius, x = 0;
    int radiusError = 1 - radius;
    while (x <= y) {
        plotOctant(xc,x,yc,y,color);
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
    int p = 3 - 2 * r;

    while (x <= y) {
        plotOctant(xc,x,yc,y,LIGHTRED);
        x++;
        if (p <= 0)
            p = p + 4 * x + 1;
        else {
            y--;
            p = p + 4 * (x - y) + 1;
        }
    }
}



int main() {

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

    setfillstyle(SOLID_FILL,LIGHTBLUE);

    for (int j = 530; j < 690; j+=30) {
        int i = 620;
        drawLineDDA(i, j, i + 20, j);

        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
        floodfill(i+3,j-3,WHITE);
    }

    for (int j = 400; j < 690; j+=30) {
        int i = 661;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
        floodfill(i+3,j-3,WHITE);
    }
    for (int j = 295; j < 690; j+=30) {
        int i = 700;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
        floodfill(i+3,j-3,WHITE);
    }

    for (int j = 195; j < 690; j+=30) {
        int i = 737;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
        floodfill(i+3,j-3,WHITE);
    }
    for (int j = 227; j < 690; j+=30) {
        int i = 787;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
        floodfill(i+3,j-3,WHITE);
    }
    for (int j = 355; j < 690; j+=30) {
        int i = 822;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
        floodfill(i+3,j-3,WHITE);
    }
    for (int j = 467; j < 690; j+=30) {
        int i = 858;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
        floodfill(i+3,j-3,WHITE);
    }
    for (int j = 562; j < 690; j+=30) {
        int i = 898;
        drawLineDDA(i, j, i + 20, j);
        drawLineDDA(i + 20, j, i + 20, j - 20);
        drawLineDDA(i + 20, j - 20, i, j - 20);
        drawLineDDA(i, j - 20, i, j);
        floodfill(i+3,j-3,WHITE);
    }

    setfillstyle(SOLID_FILL,LIGHTGRAY );
    floodfill(780,680,WHITE);
    //drawLineDDA(773,690,773,106);


    drawCircle(200, 150, 54,YELLOW); // Outer circle
    drawCircle(200, 150, 52,YELLOW); // Outer circle
    setfillstyle(SOLID_FILL,YELLOW );
    floodfill(253,150,YELLOW);

    drawCircleBresenham(200, 150, 40); // Middle circle
    drawCircleBresenham(200, 150, 41); // Middle circle

    drawCircle(200, 150, 30,YELLOW); // Inner circle

    drawCircle(200,150,55,LIGHTGRAY);
    int rayLength = 25 , Offset = 1;

    //SUN
    while(true) {

        rayLength += Offset;
        for (int angle = 0; angle < 360; angle += 20) {
            int color = YELLOW;

            //if(angle%40==0){
            //    color = RED;
            //}

            int x1 = 200 + 65 * cos(angle * 3.14 / 180);
            int y1 = 150 + 65 * sin(angle * 3.14 / 180);
            int x2 = 200 + (65 + rayLength) * cos(angle * 3.14 / 180);
            int y2 = 150 + (65 + rayLength) * sin(angle * 3.14 / 180);
            drawLineBresenham(x1, y1, x2, y2,color);
        }
        if(rayLength>=50 ){
            setfillstyle(SOLID_FILL,BLACK);
            drawCircle(200,150,55,LIGHTGRAY);
            floodfill(1000,700,LIGHTGRAY);
            rayLength = 10;
        }
        delay(5);
        if(kbhit()){
            break;
        }
    }
    getch();
    cleardevice();
    closegraph();
    return 0;
}
