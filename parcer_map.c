#include <unistd.h>
#include <fcntl.h>
#include <string.h> 
#include <stdio.h>
#include "get_next_line.h"

int ft_isalpha(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] < '0' || str[i] > '9')
            return -1;
        i++;
    }
    return 0;
}


int ft_lastindex(char *str, int find)
{
    int i = strlen(str) - 1;
    while(i > 0)
    {
        if(str[i] == find)
            return i;
        i--;
    }
    return -1;
}

int parcer_map(t_vars *vs)
{
    char *tmp = NULL;
    char **arr = NULL;
    char **color = NULL;
    int i = 0;
    int fd= open("./map/map.cub", O_RDONLY);
    int fd1 = open("./map/map.cub", O_RDONLY);
    tmp = calloc(2, sizeof(char ));
    if(fd < 0)
    {
        return -1;
    }
    tmp = get_next_line(fd);
    while(tmp != NULL)
    {
            i++;
        free(tmp);
        tmp = get_next_line(fd);

    }
    vs->store_map = calloc(sizeof(char *), (i - 5));
    vs->texture = calloc(sizeof(char *), 7);
    i = 0;
    while(i < 6)
    {
        vs->texture[i] = calloc(sizeof(char *),1);
        i++;
    }
    close(fd);
    i = 0;
    // stote data fo vs->texture in 2D array format
    while(i < 6)
    {
        tmp = get_next_line(fd1);
        if(tmp[0] != '\n')
        {
            vs->texture[i] = ft_split(tmp, ' ');
            i++;
        }
        free(tmp);
    }
    // store data of map items in 2D array  format
    tmp = get_next_line(fd1);
    i = 0;
    int check = 0;
    while(tmp != NULL)
    {
        if(tmp[0] != '\n')
            check = 1;
        if( check == 1)
        {
            vs->store_map[i] = strdup(tmp);
            i++;
        }
        free(tmp);
        tmp = get_next_line(fd1);
    }
    // free(tmp);
    i = 0;
    int j = 0;
    while(i < 6)
    {
        if(strlen(vs->texture[i][0]) == 2)
        {
            if(strncmp(vs->texture[i][0], "NO", 2) == 0 || strncmp(vs->texture[i][0], "SO", 2) == 0
            || strncmp(vs->texture[i][0], "WE", 2) == 0 || strncmp(vs->texture[i][0], "EA", 2) == 0)
            {
                j++;
            }
            else
            {   
                printf("vs->texture not available");
                return(0);
            }
        }
        else if(strlen(vs->texture[i][0]) == 1)
        {
            if( strncmp(vs->texture[i][0], "F",1) == 0|| strncmp(vs->texture[i][0], "C",1) == 0)
                j++;
            else
            {
                    // puts("heref");
                printf("vs->texture not available");
                return(0);
            }  
        }
        else
        {
         
            return(1);   perror("vs->texture don't  respect the rules");
        }
       i++;
    }
    if(i != j)
    {
        perror("vs->texture don't  respect the rules");
        return(0);
    }
    // j = 0;
    i = 0;
    while(i < j - 1)
    {
         int k = 0;
         while(vs->texture[k] != NULL)
         {
            if(k == i)
              k++;
            else if(strcmp(vs->texture[k][0], vs->texture[i][0]) == 0)
            {
                printf("vs->texture duplicated");
                return(0);
            }
            k++;

         }  
         i++; 
    }
    i = 0;
    close(fd);
    while(vs->texture[i] != NULL)
    {
        if(strncmp(vs->texture[i][0], "F", 1) == 0 || strncmp(vs->texture[i][0], "C", 1) == 0)
        {
            tmp = ft_substr(vs->texture[i][1], 0, strlen(vs->texture[i][1]) - 1);
            if(tmp == NULL)
                return(0);
            color = ft_split(tmp, ',');
            free(tmp);
            j = 0;
            while(color[j] != NULL)
            {
                if(ft_isalpha(color[j]) == -1 || ft_atoi(color[j]) < 0 || ft_atoi(color[j]) > 255)
                {
                    printf("color not acceptable");
                    return(0);
                }
                j++;
            }
        }

        i++;
    }
    i = 0;
    while(vs->texture[i] != NULL)
    {
       if(strcmp(vs->texture[i][0], "NO") == 0)
            vs->img_N = ft_substr(vs->texture[i][1], 0,found_nl(vs->texture[i][1], '\n'));
       if(strcmp(vs->texture[i][0], "SO") == 0)
            vs->img_S = ft_substr(vs->texture[i][1], 0,found_nl(vs->texture[i][1], '\n'));
       if(strcmp(vs->texture[i][0], "WE") == 0)
            vs->img_W = ft_substr(vs->texture[i][1], 0,found_nl(vs->texture[i][1], '\n'));
       if(strcmp(vs->texture[i][0], "EA") == 0)
            vs->img_E =ft_substr(vs->texture[i][1], 0,found_nl(vs->texture[i][1], '\n'));
       if(strcmp(vs->texture[i][0], "F") == 0)
           {
                vs->fl_ceil = calloc(sizeof(int *), 4);
                j = 0;
                arr = ft_split(vs->texture[i][1], ',');
                while(j < 3)
                {   
                    vs->fl_ceil[j] = ft_atoi(arr[j]);
                    // free(arr[j]);
                    j++;
                }

           }
        if(strcmp(vs->texture[i][0], "C") == 0)
           {
                // i = 0;
                vs->fl_floor = calloc(sizeof(int *), 4);
                j = 0;
                arr = ft_split(vs->texture[i][1], ',');
                while(j < 3)
                {   
                    vs->fl_floor[j] = ft_atoi(arr[j]);
                    free(arr[j]);
                    j++;
                }
           }
        i++;
    }
    free(arr);
    return(1);
}