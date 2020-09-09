/**
 * Created by raven on 2020/9/9.
 * 迷宫求解
 */
#include "../顺序栈/sq_stack.cpp"
#include <fstream>
#include <sstream>


enum point_type {
    ROAD = 0, WALL = 1
};

#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4
#define DISABLE 5

/* 迷宫方格 */
typedef struct {
    int x, y;        /* 座标 */
    point_type type;
    int direction;      /* 1 right, 2 down, 3 left 4 up 5 disable */
    bool footprint;     /* 是否已经走过 */
} point;


bool operator==(point a, point b)
{
    return a.x == b.x && a.y == b.y;
}

class maze {
public:
    maze(int width, int height);
    
    ~maze();
    
    Status init_maze(const std::string &path);
    
    Status print_maze() const;
    
    Status print_one_solution(point start, point end) const;

private:
    point *next_point(const point &cur) const;

private:
    int width;
    int height;
    point **_maze;
};

maze::maze(int width, int height)
{
    this->width = width;
    this->height = height;
    /* height */
    _maze = (point **) malloc(sizeof(point *) * height);
    /* width */
    for (size_t i = 0; i < height; i++) {
        _maze[i] = (point *) malloc(sizeof(point) * width);
    }
}

maze::~maze()
{
    for (size_t i = 0; i < height; i++) {
        free(_maze[i]);
    }
    free(_maze);
}

Status maze::init_maze(const std::string &path)
{
    std::ifstream in(path);
    int temp;
    
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            in >> temp;
            _maze[i][j].x = i;
            _maze[i][j].y = j;
            _maze[i][j].direction = RIGHT;
            _maze[i][j].type = temp == 1 ? WALL : ROAD;
            _maze[i][j].footprint = temp == 1;
        }
    }
    return OK;
}

Status maze::print_maze() const
{
    std::cout << "maze:\n";
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            std::cout << _maze[i][j].type << " ";
        }
        std::cout << "\n";
    }
    return OK;
}

Status maze::print_one_solution(point start, point end) const
{
    sqstack<point *> stack;
    point *cur;
    point *next_pos;
    
    /* validation check */
    if (start.type != ROAD || end.type != ROAD) {
        std::cerr << "input invalid\n";
        return ERROR;
    }
    
    /* find one solution */
    cur = &start;
    do {
        if (cur->type == ROAD && cur->direction != DISABLE) {
            cur->footprint = true;
            stack.push(cur);
            if (*cur == end) {      /* find the solution, break */
                break;
            }
            /* go to next point in terms of current direction */
            next_pos = next_point(*cur);
            cur = next_pos;
        } else {
            /* find next usable point */
            while (!stack.isempty()) {
                stack.gettop(cur);
                cur->direction++;
                if (cur->direction == DISABLE) {
                    stack.pop(cur);
                    continue;
                }
                
                /* 基于当前点，找下一个可用点 */
                next_pos = next_point(*cur);
                if (next_pos->type != WALL && !next_pos->footprint && next_pos->direction != DISABLE) { /* 找到了可走点 */
                    cur = next_pos;
                    break;
                }
            }
        }
    } while (!stack.isempty());
    
    if (stack.isempty()) {
        std::cout << "infeasible\n";
        return INFEASIBLE;
    }
    
    sqstack<point *> solution;
    point *temp;
    while (!stack.isempty()) {
        stack.pop(temp);
        solution.push(temp);
    }
    while (!solution.isempty()) {
        solution.pop(temp);
        std::cout << temp->x << "," << temp->y << "\n";
    }
    return OK;
}

point *maze::next_point(const point &cur) const
{
    int i = 0, j = 0;
    switch (cur.direction) {
        case RIGHT:
            j = cur.y + 1;
            i = cur.x;
            break;
        case DOWN:
            j = cur.y;
            i = cur.x + 1;
            break;
        case LEFT:
            j = cur.y - 1;
            i = cur.x;
            break;
        case UP:
            j = cur.y;
            i = cur.x - 1;
            break;
        default:
            break;
        
    }
    return &_maze[i][j];
}

int main()
{
    maze maze1(5, 5);
    maze1.init_maze("/home/raven/Projects/MyLeetCode/0.数据结构/2.栈/应用例子/maze_input.txt");
    maze1.print_maze();
    
    point start = {
            .x = 1, .y = 1, .type=ROAD, .direction=RIGHT, .footprint = false
    };
    point end = {
            .x=1, .y=3, .type=ROAD, .direction = RIGHT, .footprint = false
    };
    maze1.print_one_solution(start, end);
    return 0;
}