#include <stdio.h> 
#define MAX 20 
// Function to find whether a page exists in a frame 
int is_page_in_frame(int frames[], int frame_size, int page) { 
    for (int i = 0; i < frame_size; i++) { 
        if (frames[i] == page) 
            return 1; // Page is found 
    }    return 0; // Page not found 
} 
// Function to find the optimal page to replace 
int find_optimal(int frames[], int pages[], int frame_size, int n, int index) { 
    int farthest = index, res = -1; 
    for (int i = 0; i < frame_size; i++) { 
        int j; 
        for (j = index; j < n; j++) { 
            if (frames[i] == pages[j]) { 
                if (j > farthest) { 
                    farthest = j; 
                    res = i; 
                }                break; 
            }        } 
        if (j == n) // If the page is never used again 
            return i; 
    } 
    return (res == -1) ? 0 : res; 
} 
// FCFS Page Replacement Algorithm 
void fcfs(int pages[], int n, int frame_size) { 
    int frames[MAX], page_faults = 0, index = 0; 
    printf("\nFCFS Page Replacement Algorithm:\n"); 
    for (int i = 0; i < frame_size; i++) 
        frames[i] = -1; 
    for (int i = 0; i < n; i++) { 
        printf("Page %d: ", pages[i]); 
        if (!is_page_in_frame(frames, frame_size, pages[i])) { 
            frames[index] = pages[i]; 
            index = (index + 1) % frame_size; 
            page_faults++; 
            printf("Page fault! Frames: "); 
        } else { 
            printf("No page fault. Frames: "); 
        } 
        for (int j = 0; j < frame_size; j++) { 
            if (frames[j] != -1) 
                printf("%d ", frames[j]); 
            else 
                printf("- "); 
        } 
        printf("\n"); 
    } 
    printf("Total Page Faults (FCFS): %d\n", page_faults); 
} 
// LRU Page Replacement Algorithm 
void lru(int pages[], int n, int frame_size) { 
    int frames[MAX], recent[MAX], page_faults = 0, time = 0; 
 
    printf("\nLRU Page Replacement Algorithm:\n"); 
    for (int i = 0; i < frame_size; i++) { 
        frames[i] = -1; 
        recent[i] = 0; 
    } 
    for (int i = 0; i < n; i++) { 
        printf("Page %d: ", pages[i]); 
        if (!is_page_in_frame(frames, frame_size, pages[i])) { 
            int lru_index = 0; 
            for (int j = 1; j < frame_size; j++) { 
                if (recent[j] < recent[lru_index]) { 
                    lru_index = j; 
                }            } 
            frames[lru_index] = pages[i]; 
            page_faults++; 
            printf("Page fault! Frames: "); 
        } else { 
            printf("No page fault. Frames: "); 
        } 
        for (int j = 0; j < frame_size; j++) { 
            if (frames[j] != -1) 
                printf("%d ", frames[j]); 
            else 
                printf("- "); 
        } 
        printf("\n"); 
        for (int j = 0; j < frame_size; j++) { 
            if (frames[j] == pages[i]) { 
                recent[j] = time++; 
                break;            }        }    } 
    printf("Total Page Faults (LRU): %d\n", page_faults); 
} 
// Optimal Page Replacement Algorithm 
void optimal(int pages[], int n, int frame_size) { 
    int frames[MAX], page_faults = 0; 
    printf("\nOptimal Page Replacement Algorithm:\n"); 
    for (int i = 0; i < frame_size; i++) 
        frames[i] = -1; 
    for (int i = 0; i < n; i++) { 
        printf("Page %d: ", pages[i]); 
        if (!is_page_in_frame(frames, frame_size, pages[i])) { 
            if (i < frame_size) { 
                frames[i] = pages[i]; 
            } else { 
                int replace_index = find_optimal(frames, pages, frame_size, n, i + 1); 
                frames[replace_index] = pages[i]; 
            } 
            page_faults++; 
            printf("Page fault! Frames: "); 
        } else { 
            printf("No page fault. Frames: "); 
        } 
        for (int j = 0; j < frame_size; j++) { 
            if (frames[j] != -1) 
                printf("%d ", frames[j]); 
            else 
                printf("- "); 
        }        printf("\n");    } 
    printf("Total Page Faults (Optimal): %d\n", page_faults); 
} 
int main() { 
    int n, frame_size, pages[MAX]; 
    printf("Enter the number of pages: "); 
    scanf("%d", &n); 
 
    printf("Enter the reference string (page numbers): "); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &pages[i]); 
    } 
 
    printf("Enter the frame size (minimum 3): "); 
    scanf("%d", &frame_size); 
 
    if (frame_size < 3) { 
        printf("Frame size should be at least 3!\n"); 
        return 1; 
    } 
 
    fcfs(pages, n, frame_size); 
    lru(pages, n, frame_size); 
    optimal(pages, n, frame_size); 
 
    return 0; 
}
