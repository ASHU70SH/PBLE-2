#include <stdio.h> 
#include <string.h> 

#define MAX 10
#define INF 9999 

int main() { int graph[MAX][MAX]; int dist[MAX]; int visited[MAX]; int parent[MAX]; int path[MAX]; 

int n, choice, subChoice; 
int i, j, k; 
int source, destination; 
int min, u; 
int count; 
int entered = 0; 
 
char location[MAX][20]; 
 
while (1) 
{ 
   printf("\n\n***** DIJKSTRA ALGORITHM *****\n"); 
    printf("1. Enter Locations\n"); 
    printf("2. Adjacency Matrix\n"); 
    printf("3. Source Node\n"); 
    printf("4. Exit\n"); 
    printf("**********************************\n");
 
    printf("Enter choice: "); 
    scanf("%d", &choice); 
 
    //  ENTER LOCATIONS  
 
    if (choice == 1) 
    { 
        printf("\nEnter number of locations: "); 
        scanf("%d", &n); 
 
        for (i = 0; i < n; i++) 
        { 
            printf("Enter location %d: ", i); 
            scanf(" %[^\n]", location[i]); 
        } 
 
        printf("\nEnter distances:\n"); 
 
        for (i = 0; i < n; i++) 
        { 
            for (j = i + 1; j < n; j++) 
            { 
                printf("Distance %s - %s: ", 
                       location[i], location[j]); 
 
                scanf("%d", &graph[i][j]); 
 
                graph[j][i] = graph[i][j]; 
            } 
        } 
 
        //Distance from a location to itself  
 
        for (i = 0; i < n; i++) 
        { 
            graph[i][i] = 0; 
        } 
 
        entered = 1; 
 
        printf("\nLocations entered successfully!"); 
    } 
 
     // ADJACENCY MATRIX  
 
    else if (choice == 2) 
    { 
        if (entered == 0) 
        { 
            printf("\nEnter locations first!"); 
        } 
        else 
        { 
            printf("\n***** ADJACENCY MATRIX *****\n"); 
 
            for (i = 0; i < n; i++) 
            { 
                for (j = 0; j < n; j++) 
                { 
                    printf("%d\t", graph[i][j]); 
                } 
 
                printf("\n"); 
            } 
        } 
    } 
 
    // SOURCE NODE  
 
    else if (choice == 3) 
    { 
        if (entered == 0) 
        { 
            printf("\nEnter locations first!"); 
        } 
        else 
        { 
            printf("\nLocations:\n"); 
 
            for (i = 0; i < n; i++) 
            { 
                printf("%d. %s\n", i, location[i]); 
            } 
 
            printf("\nEnter source node: "); 
            scanf("%d", &source); 
 
            /* Dijkstra Initialization */ 
 
            for (i = 0; i < n; i++) 
            { 
                dist[i] = INF; 
                visited[i] = 0; 
                parent[i] = -1; 
            } 
 
            dist[source] = 0; 
 
            /* Dijkstra Algorithm */ 
 
            for (i = 0; i < n; i++) 
            { 
                min = INF; 
                u = -1; 
 
                /* Find nearest unvisited node */ 
 
                for (j = 0; j < n; j++) 
                { 
                    if (visited[j] == 0 && 
                        dist[j] < min) 
                    { 
                        min = dist[j]; 
                        u = j; 
                    } 
                } 
 
                if (u == -1) 
                { 
                    break; 
                } 
 
                visited[u] = 1; 
 
                // Update distances  
 
                for (j = 0; j < n; j++) 
                { 
                    if (graph[u][j] != 0 && 
                        visited[j] == 0 && 
                        dist[u] + graph[u][j] < dist[j]) 
                    { 
                        dist[j] = dist[u] + graph[u][j]; 
 
                        parent[j] = u; 
                    } 
                } 
            } 
 
            // SOURCE NODE MENU  
 
            while (1) 
            { 
                printf("\n\n***** SOURCE NODE MENU *****\n"); 
                printf("Source: %s\n", location[source]); 
 
                printf("1. Shortest Path\n"); 
                printf("2. Shortest Distance\n"); 
                printf("3. Distance from Source to All Locations\n"); 
                printf("4. Back\n"); 
                printf("**********************************\n");
 
                printf("Enter choice: "); 
                scanf("%d", &subChoice); 
 
                // SHORTEST PATH  
 
                if (subChoice == 1) 
                { 
                    printf("\nEnter destination node: "); 
                    scanf("%d", &destination); 
 
                    if (dist[destination] == INF) 
                    { 
                        printf("No path exists!"); 
                    } 
                    else 
                    { 
                        count = 0; 
                        k = destination; 
 
                        while (k != -1) 
                        { 
                            path[count] = k; 
                            count++; 
                            k = parent[k]; 
                        } 
 
                        printf("\nShortest Path: "); 
 
                        for (i = count - 1; i >= 0; i--) 
                        { 
                            printf("%s", location[path[i]]); 
 
                            if (i != 0) 
                            { 
                                printf(" -> "); 
                            } 
                        } 
                    } 
                } 
 
                // SHORTEST DISTANCE  
 
                else if (subChoice == 2) 
                { 
                    printf("\nEnter destination node: "); 
                    scanf("%d", &destination); 
 
                    if (dist[destination] == INF) 
                    { 
                        printf("No path exists!"); 
                    } 
                    else 
                    { 
                        printf("\nShortest Distance = %d", 
                               dist[destination]); 
                    } 
                } 
 
                // DISTANCE TO ALL  
 
                else if (subChoice == 3) 
                { 
                    printf("\nDistance from %s:\n", 
                           location[source]); 
 
                    for (i = 0; i < n; i++) 
                    { 
                        if (dist[i] == INF) 
                        { 
                            printf("%s = No Path\n", 
                                   location[i]); 
                        } 
                        else 
                        { 
                            printf("%s = %d\n", 
                                   location[i], 
                                   dist[i]); 
                        } 
                    } 
                } 
 
                // BACK  
 
                else if (subChoice == 4) 
                { 
                    break; 
                } 
 
                else 
                { 
                    printf("Invalid choice!"); 
                } 
            } 
        } 
    } 
 
    // EXIT 
 
    else if (choice == 4) 
    { 
        printf("\nProgram ended."); 
        break; 
    } 
 
    else 
    { 
        printf("\nInvalid choice!"); 
    } 
} 
 
return 0; 
} 