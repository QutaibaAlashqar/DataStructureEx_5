

/// QUTAIBA ALASHQAR, 20290036.
/// DATA STRUCRUE, LAB 5;


#include<stdio.h>
#include<stdlib.h>


#define SIZE1 50
#define SIZE2 6


void add_onther(int, int, int);
int function2();
int control();


int emp_count = -1;
int cus_count = 0;


typedef struct customer{

	int account_number;
	int arrival_time;
	int execution_time;
	int waiting_time;
	int assigned_emp;
}customer;


typedef struct employee{

	int emp_code;
	int service_time;
	int limit_time;
	int service_count;
}employee;


employee *stack[SIZE2];
employee *ser[SIZE2];
employee *emp_lis[SIZE2];
customer *que_cus[SIZE1];


void add_onther(int account_number, int arrival_time, int execution_time){

    employee *emppp;
	customer *cus1 = (customer*)malloc(sizeof(customer));
	(cus1-> account_number) = account_number;
	(cus1-> arrival_time) = arrival_time;
	(cus1-> execution_time) = execution_time;
	(cus1-> waiting_time) = (0);
	(cus1-> assigned_emp) = (-1);
	//(cus1-> execution_time) = execution_time;
	//(cus1-> waiting_time) = (0);
	//(cus1-> assigned_emp) = (-1);
	que_cus[cus_count++] = cus1;
	//que_cus[cus_count++] = cus1;
}


int function2(customer *cus2){

    int flag2 = 0;
	if(emp_count == -1){

		(cus2-> waiting_time)++;
		flag2 = 1;
		return (0);
	}

	else{

		employee *empp = stack[emp_count];
		flag2 = 0;
		(cus2-> assigned_emp) = (empp-> emp_code);
		emp_count--;

		for(int i = 0; i < SIZE2; i++){

			if(ser[i] == NULL){

                flag2 = 1;
				(empp-> service_count) = 0;
				(empp-> limit_time) = (cus2-> execution_time);
				ser[i] = empp;
				break;
			}
		}
		flag2 = 0;
		return (1);
	}
}


int control(){

    int flag = 0;
    int rer = -1;
	int counter = 0;
	employee *stack2[SIZE2];

	for(int i = 0; i < SIZE2; i++){

		if(ser[i] != NULL){

            flag = 1;
            employee *empp;
			empp = ser[i];
			(empp-> service_count)++;
			(empp-> service_time)++;

            int em1 = (empp-> service_count);
            int em2 = (empp-> limit_time);
			if(em1 == em2){

                flag = 0;
				ser[i] = NULL;
				stack2[++rer] = empp;
			}
			counter++;
		}
	}

    int j = rer;
	while(j >= 0){

        flag = 1;
		stack[++emp_count] = stack2[j];
		j--;
	}

	flag = 0;
	return (counter > 0);
}


int main(){

	int index1, index2, index3;
	int guess;

	for(int i = 0; i < SIZE2; i++){

		employee *empp = (employee*)malloc(sizeof(employee));
		(empp-> emp_code) = (i + 1);
		(empp-> service_time) = (0);
		emp_count++;
		stack[emp_count] = empp;
		emp_lis[i] = empp;
		ser[i] = NULL;
	}

    int flag = 0;
	while(1){

		scanf("%d", &index1);

		if(index1 == -1) {
			flag = 1;
			break;
		}

		else{

			scanf("%d%d", &index2, &index3);
			add_onther(index1, index2, index3);
            flag = 0;
		}
	}

	int k = 0;
    int i = 0;

	while(cus_count){

		for(i = 0; i < cus_count; i++){

            flag = 0;
			index2 = (que_cus[i]-> arrival_time);
			guess = (que_cus[i]-> waiting_time);

			if((index2 + guess) > k){

                flag = 0;
				break;
			}

			if((index2 + guess) == k){

                flag = 0;

				if(function2(que_cus[i])){

                    flag = 0;
					continue;
				}

                else{

                    flag = 1;
					break;
				}
			}
		}

		if((i) && (!control())){
			break;
		}
		k++;
	}

	for(int j = 0; j < cus_count; j++){

		customer *cus = que_cus[j];
		guess = (cus-> waiting_time);
		index2 = (cus-> arrival_time);
		index3 = (cus-> execution_time);

		printf("%d %d %d %d %d\n", (cus-> account_number), (cus-> assigned_emp), (index2 + guess), (index3 + index2 + guess), (guess));
	}
    printf("\n");

	for(i = SIZE2 - 1; i >= 0; i--){

        employee *emm = emp_lis[i];

        if (i == 0){
            flag = 1;
            printf("%d %d", (emm-> emp_code), (emm-> service_time));
        }

        else{

            flag = 1;
            printf("%d %d\n", (emm-> emp_code), (emm-> service_time));
        }
	}

	return 0;
}
