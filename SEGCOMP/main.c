#include <stdio.h>
#include <stdlib.h>

#define KEY_SIZE 10

int s0[4][4] = {
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {0, 2, 1, 3},
    {3, 1, 3, 2}
};

int s1[4][4] = {
    {1, 1, 2, 3},
    {2, 0, 1, 3},
    {3, 0, 1, 0},
    {2, 1, 0, 3}
};

int* p10(int *key){
    int* ip_key = malloc(10*sizeof(int));
    ip_key[0] = key[2];
    ip_key[1] = key[4];
    ip_key[2] = key[1];
    ip_key[3] = key[6];
    ip_key[4] = key[3];
    ip_key[5] = key[9];
    ip_key[6] = key[0];
    ip_key[7] = key[8];
    ip_key[8] = key[7];
    ip_key[9] = key[5];
    return ip_key;
}

int* circular_ls(int* key){
    int * aux = malloc(5*sizeof(int));
    aux[0] = key[1];
    aux[1] = key[2];
    aux[2] = key[3];
    aux[3] = key[4];
    aux[4] = key[0];
    return aux;
}

int* p8(int* left, int* right){
    int * aux = malloc(8*sizeof(int));
    aux[0] = right[0];
    aux[1] = left[2];
    aux[2] = right[1];
    aux[3] = left[3];
    aux[4] = right[2];
    aux[5] = left[4];
    aux[6] = right[4];
    aux[7] = right[3];
    return aux;
}

int* ip(int* text){
    int* aux = malloc(8*sizeof(int));
    aux[0] = text[1];
    aux[1] = text[5];
    aux[2] = text[2];
    aux[3] = text[0];
    aux[4] = text[3];
    aux[5] = text[7];
    aux[6] = text[4];
    aux[7] = text[6];
    return aux;
}

int* reverse_ip(int* text){
    int* aux = malloc(8*sizeof(int));
    aux[0] = text[3];
    aux[1] = text[0];
    aux[2] = text[2];
    aux[3] = text[4];
    aux[4] = text[6];
    aux[5] = text[1];
    aux[6] = text[7];
    aux[7] = text[5];
    return aux;
}

int* ep(int* text){
    int * aux = malloc(8*sizeof(int));
    aux[0] = text[3];
    aux[1] = text[0];
    aux[2] = text[1];
    aux[3] = text[2];
    aux[4] = text[1];
    aux[5] = text[2];
    aux[6] = text[3];
    aux[7] = text[0];
    return aux;
}

int* s0_convert(int* text){
    int bit1 = text[0];
    int bit2 = text[1];
    int bit3 = text[2];
    int bit4 = text[3];
    // printf("BITS: %d %d %d %d\n", bit1, bit2, bit3, bit4);
    int * aux = malloc(2*sizeof(int));
    int row, col;
    if(bit1 == 0 && bit4 == 0) row = 0;
    if(bit1 == 0 && bit4 == 1) row = 1;
    if(bit1 == 1 && bit4 == 0) row = 2;
    if(bit1 == 1 && bit4 == 1) row = 3;

    if(bit2 == 0 && bit3 == 0) col = 0;
    if(bit2 == 0 && bit3 == 1) col = 1;
    if(bit2 == 1 && bit3 == 0) col = 2;
    if(bit2 == 1 && bit3 == 1) col = 3;

    int s0_val = s0[row][col];
    // printf("S0: %d\n", s0_val);
    if(s0_val == 0){
        aux[0] = 0; aux[1] = 0;
    }
    if(s0_val == 1){
        aux[0] = 0; aux[1] = 1;
    }
    if(s0_val == 2){
        aux[0] = 1; aux[1] = 0;
    }
    if(s0_val == 3){
        aux[0] = 1; aux[1] = 1;
    }
    return aux;
}

int* s1_convert(int* text){
    int bit1 = text[0];
    int bit2 = text[1];
    int bit3 = text[2];
    int bit4 = text[3];
    int * aux = malloc(2*sizeof(int));
    int row, col;
    if(bit1 == 0 && bit4 == 0) row = 0;
    if(bit1 == 0 && bit4 == 1) row = 1;
    if(bit1 == 1 && bit4 == 0) row = 2;
    if(bit1 == 1 && bit4 == 1) row = 3;

    if(bit2 == 0 && bit3 == 0) col = 0;
    if(bit2 == 0 && bit3 == 1) col = 1;
    if(bit2 == 1 && bit3 == 0) col = 2;
    if(bit2 == 1 && bit3 == 1) col = 3;

    int s1_val = s1[row][col];
    if(s1_val == 0){
        aux[0] = 0; aux[1] = 0;
    }
    if(s1_val == 1){
        aux[0] = 0; aux[1] = 1;
    }
    if(s1_val == 2){
        aux[0] = 1; aux[1] = 0;
    }
    if(s1_val == 3){
        aux[0] = 1; aux[1] = 1;
    }
    return aux;
}

int* p4(int* left, int* right){
    int* aux = malloc(4*sizeof(int));
    aux[0] = left[1];
    aux[1] = right[1];
    aux[2] = right[0];
    aux[3] = left[0];
    return aux;
}

int* fk(int*l, int*r, int* key){
    int *ep_text = ep(r);

    int* xor_k1_key = malloc(8*sizeof(int));
    int* xor_k1_key_l = malloc(4*sizeof(int));
    int* xor_k1_key_r = malloc(4*sizeof(int));

    for(int i = 0; i < 8; i++){
        xor_k1_key[i] = key[i] ^ ep_text[i];
    }

    for (int i = 0; i < 4; i++){
        xor_k1_key_r[i] = xor_k1_key[i+4];
        xor_k1_key_l[i] = xor_k1_key[i];
    }

    int* s0_l = s0_convert(xor_k1_key_l);
    int* s1_r = s1_convert(xor_k1_key_r);

    int* p4_text = p4(s0_l, s1_r);

    return p4_text;
}

void cifra(char* key, char* text){
    int int_key[11];
    for(int i = 0; i < 10; i++){
        int_key[i] = key[i] - '0';   
    }

    int* p10_key = p10(int_key);
    int* r = malloc(5*sizeof(int));
    int* l = malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++){
        r[i] = p10_key[i+5];
        l[i] = p10_key[i];
    }

    r = circular_ls(r);
    l = circular_ls(l);

    int * p8_key1 = p8(l, r);

    r = circular_ls(circular_ls(r));
    l = circular_ls(circular_ls(l));

    int * p8_key2 = p8(l, r);

    int int_text[9];
    for(int i = 0; i < 8; i++){
        int_text[i] = text[i] - '0';   
    }

    int *ip_text = ip(int_text);
    for (int i = 0; i < 4; i++){
        r[i] = ip_text[i+4];
        l[i] = ip_text[i];
    }

    int* p4_text = fk(l, r, p8_key1);
    int* sw_r = malloc(4*sizeof(int));
    int* sw_l = malloc(4*sizeof(int));

    for(int i = 0; i < 4; i++){
        sw_r[i] = p4_text[i] ^ l[i];
        sw_l[i] = r[i];
    }

    int* p4_text_2 = fk(sw_l, sw_r, p8_key2);
    int* pre_rev_ip  = malloc(8*sizeof(int));

    for(int i = 0; i < 4; i++){
        pre_rev_ip[i] = p4_text_2[i] ^ sw_l[i];
        pre_rev_ip[i+4] = sw_r[i];
    }

    int* rev_ip = reverse_ip(pre_rev_ip);

    for(int i = 0; i < 8; i++){
        printf("%d", rev_ip[i]);
    }
    printf("\n");
}

void decifra(char* key, char* text){
    int int_key[11];
    for(int i = 0; i < 10; i++){
        int_key[i] = key[i] - '0';   
    }

    int* p10_key = p10(int_key);
    int* r = malloc(5*sizeof(int));
    int* l = malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++){
        r[i] = p10_key[i+5];
        l[i] = p10_key[i];
    }

    r = circular_ls(r);
    l = circular_ls(l);

    int * p8_key1 = p8(l, r);

    r = circular_ls(circular_ls(r));
    l = circular_ls(circular_ls(l));

    int * p8_key2 = p8(l, r);

    int int_text[9];
    for(int i = 0; i < 8; i++){
        int_text[i] = text[i] - '0';   
    }

    int *ip_text = ip(int_text);
    for (int i = 0; i < 4; i++){
        r[i] = ip_text[i+4];
        l[i] = ip_text[i];
    }

    int* p4_text = fk(l, r, p8_key2);
    int* sw_r = malloc(4*sizeof(int));
    int* sw_l = malloc(4*sizeof(int));

    for(int i = 0; i < 4; i++){
        sw_r[i] = p4_text[i] ^ l[i];
        sw_l[i] = r[i];
    }

    int* p4_text_2 = fk(sw_l, sw_r, p8_key1);
    int* pre_rev_ip  = malloc(8*sizeof(int));

    for(int i = 0; i < 4; i++){
        pre_rev_ip[i] = p4_text_2[i] ^ sw_l[i];
        pre_rev_ip[i+4] = sw_r[i];
    }

    int* rev_ip = reverse_ip(pre_rev_ip);

    for(int i = 0; i < 8; i++){
        printf("%d", rev_ip[i]);
    }
    printf("\n");
}

int main(){
    int op_num;
    char operation;
    char key[11], text[9];

    scanf("%d", &op_num);

    for(int i = 0; i < op_num; i++){
        scanf(" %c", &operation);
        scanf("%s", key);
        scanf("%s", text);
        if(operation == 'C'){
            cifra(key, text);
        }else{
            decifra(key, text);
        }
    }   

    return 0;
}