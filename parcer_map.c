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
    int i = strlen(str);
    while(i != 0)
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
    char **color = NULL;
    int i = 0;
    int fd= open("./map/map.cub", O_RDONLY);
    int fd1 = open("./map/map.cub", O_RDONLY);
    if(fd < 0)
    {
        return -1;
    }
    tmp = get_next_line(fd);
    while(tmp != NULL)
    {
        if(tmp[0] != '\n')
            i++;
        tmp = get_next_line(fd);
        free(tmp);
        
    }
    vs->texture = calloc(sizeof(char *), 7);
    vs->store_map = calloc(sizeof(char *), (i - 5));
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
    while(tmp != NULL)
    {
        if(tmp[0] != '\n')
        {
            vs->store_map[i] = strdup(tmp);
            i++;
        }
        free(tmp);
        tmp = get_next_line(fd1);
    }
    i = 0;
    int j = 0;
    while(vs->texture[i] != NULL)
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
                    puts("heref");
                printf("vs->texture not available");
                return(0);
            }  
        }
        else
        {
            perror("vs->texture don't  respect the rules");
            return(0);
        }
       i++;
    }
    if(i != j)
    {
        // puts("here");
        perror("vs->texture don't  respect the rules");
        return(0);
    }
    // j = 0;
    i = 0;
    while(i < j)
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
            i++;
        }
        else
        {
            tmp = ft_substr(vs->texture[i][1], 0, strlen(vs->texture[i][1]) - 1);
            if(tmp == NULL)
                return(0);
            fd = open(tmp, O_RDWR);
            if(fd < 0)
                return(0);
            free(tmp);
            tmp = ft_substr(tmp, ft_lastindex(tmp, '.'), strlen(tmp));
            if(tmp == NULL)
                return(0);
            if(strncmp(tmp, ".xpm", strlen(tmp)) != 0)
                    return(0);
            free(tmp);
            i++;
        }
    }
    return(1);
}