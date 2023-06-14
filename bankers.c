#include<stdio.h>
#include<stdbool.h>

void main(){

    int total_processes, total_resources;

    printf("Enter the number of processes in the system: ");
    scanf("%d", &total_processes);

    printf("Enter the number of resources in the system: ");
    scanf("%d", &total_resources);

    int RESOURCE_INSTANCES[total_resources];
    
    printf("\n");

    for(int i=0 ; i<total_resources ; i++){
        printf("Enter the number of instances of resource R%d: ", i+1);
        scanf("%d", &RESOURCE_INSTANCES[i]);
    }

    printf("\n[NUMBER OF INSTANCES OF RESOURCES]\n");

    for(int i=0 ; i<total_resources ; i++){
        printf("R%d = %d\t", i+1, RESOURCE_INSTANCES[i]);
    }

    // ========================================== ALLOCATION MATRIX ==========================================//
    int ALLOCATION_MATRIX[total_processes][total_resources];

    printf("\n\n");

    for(int i=0; i<total_processes; i++){
        for(int j=0; j<total_resources; j++){
            printf("Number of instance of R%d allocated to P%d: ", j+1, i+1);
            scanf("%d", &ALLOCATION_MATRIX[i][j]);
        }
            printf("\n");
    }

    // ========================================== MAXIMUM MATRIX ==========================================//
    int MAXIMUM_MATRIX[total_processes][total_resources];

    printf("\n\n");

    for(int i=0; i<total_processes; i++){
        for(int j=0; j<total_resources; j++){
            printf("Max. number of instance of R%d wanted by P%d: ", j+1, i+1);
            scanf("%d", &MAXIMUM_MATRIX[i][j]);
        }
            printf("\n");
    }

    // ========================================== NEED MATRIX ==========================================//
    int NEED_MATRIX[total_processes][total_resources];

    for(int i=0; i<total_processes; i++){
        for(int j=0; j<total_resources; j++){
            NEED_MATRIX[i][j] = MAXIMUM_MATRIX[i][j] - ALLOCATION_MATRIX[i][j];
        }
    }

    for(int process=0; process<total_processes; process++){
        printf("\nPROCESS P%d\n", process+1);

        for(int j=0; j<total_resources; j++){
            printf("Allocated: %d Maximum: %d Needed: %d\n", ALLOCATION_MATRIX[process][j], MAXIMUM_MATRIX[process][j], NEED_MATRIX[process][j]);
        }
    }

    // ========================================== INITIAL AVAILABILITY ==========================================//

    for(int resource=0; resource<total_resources; resource++){
        for(int process=0; process<total_processes; process++){    
            RESOURCE_INSTANCES[resource] -= ALLOCATION_MATRIX[process][resource];
        }
    }
   
    printf("\n[AVAILABILITY]\n");

    for(int i=0 ; i<total_resources ; i++){
        printf("R%d = %d\t", i+1, RESOURCE_INSTANCES[i]);
    }

    // ========================================== SAFE SEQUENCE ==========================================//
    bool can_be_allocated = false;

    for(int i=0; i<total_processes; i++){
        for(int j=0; j<total_processes; j++){

            // check need <= availabilty
            for(int k=0; k<total_resources; k++){
                can_be_allocated = true;
                if(!(NEED_MATRIX[j][k] <= RESOURCE_INSTANCES[k])){
                    can_be_allocated = false;
                }
            }

            if(can_be_allocated){
                
            }
        }
    }
}