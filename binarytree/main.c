//
//  main.c
//  binarytree
//
//  Created by Денис Скоробогатов on 12.04.17.
//  Copyright © 2017 Denis Skorobogatov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct _vertex {
    struct _vertex* left;
    struct _vertex* right;
    int value;
} vertex_t;

vertex_t* createvertex(int value)
{
    vertex_t* root = (vertex_t*) malloc(sizeof(vertex_t));
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void createtree(vertex_t* root, int value)
{
    if (value > root->value)
    {
        if (root->right != NULL)
            return createtree(root->right, value);
        /* else */
        root->right = createvertex(value);
        return;
    }
    /* else */
    if (root->left != NULL)
        return createtree(root->left, value);
    /*else */
    root->left = createvertex(value);
    return;
}

vertex_t* searchmin(vertex_t* root)
{
    if (root->left != NULL)
        return searchmin(root->left);
    return root;
}

vertex_t* searchmax(vertex_t* root)
{
    if (root->right != NULL)
        return searchmax(root->right);
    return root;
}

int main(int argc, const char * argv[]) {
    int *array;
    int i;
    int size;
    vertex_t* root;
    printf("GIMME the array size\n");
    scanf("%d", &size);
    array = (int*) malloc(size * sizeof(int));
    srand((int)time(NULL));
    for (i = 0; i < size; i++)
    {
        array[i] = rand() % 1000;
        printf("%d ", array[i]);
    }
    printf("\n");
    root = createvertex(*array);
    for (i = 1; i <size; i++)
        createtree(root, array[i]);
    printf("%d\n", searchmin(root)->value);
    printf("%d\n", searchmax(root)->value);
    return 0;
}
