#include <stdio.h>
#include <iostream>

using namespace std;

int h, w, k, s, size;

void dfs(char* maze, bool* visited, int index) {
    if(s == 0)
        return;

    if(maze[index] == '.' && visited[index]) {
        --s;
        visited[index] = false;

        if(index - w >= 0) {
            dfs(maze, visited, index - w);
        }
        if(index + w < size) {
            dfs(maze, visited, index + w);
        }
        if(index % w > 0) {
            dfs(maze, visited, index - 1);
        }
        if(index % w < w - 1) {
            dfs(maze, visited, index + 1);
        }
    }
}

int main() {
    cin >> h >> w >> k;

    size = h * w;

    char maze[size];
    bool visited[size];

    fill(visited, visited + size, true);

    for(int i = 0; i < h; ++i) {
        getchar();
        for(int j = 0; j < w; ++j) {
            maze[i * w + j] = getchar();
        }
    }

    if(k > 0) {
        int index;

        for(int i = 0; i < size; ++i) {
            if(maze[i] == '.') {
                index = i;
                ++s;
            }
        }

        s -= k;

        dfs(maze, visited, index);

        for(int i = 0; i < size; ++i) {
            if(maze[i] == '.' && visited[i])
                maze[i] = 'X';
        }
    }

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            putchar(maze[i * w + j]);
        }
        putchar('\n');
    }
}