#include <stdio.h>
#include <json-c/json.h>

int main() {
    FILE *f = fopen("Faturamento.json", "rb");
    if (f == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    char buffer[1024];
    struct json_object *root = NULL;
    struct json_object *dia_obj = NULL;
    struct json_object *valor_obj = NULL;
    double faturamento[30];
    double media = 0;
    int num_dias_acima_da_media = 0;
    int i, num_dias = 0;

    fread(buffer, 1, 1024, f);
    fclose(f);

    root = json_tokener_parse(buffer);

    if (root == NULL) {
        printf("Erro ao analisar arquivo JSON.\n");
        return 1;
    }

    for (i = 0; i < 30; i++) {
        dia_obj = json_object_array_get_idx(root, i);
        if (dia_obj == NULL) {
            break;
        }

        json_object_object_get_ex(dia_obj, "valor", &valor_obj);
        if (valor_obj == NULL) {
            break;
        }

        faturamento[i] = json_object_get_double(valor_obj);

        if (faturamento[i] > 0) {
            num_dias++;
            media += faturamento[i];
        }
    }

    media /= num_dias;

    double menor = faturamento[0];
    double maior = faturamento[0];

    for (i = 0; i < num_dias; i++) {
        if (faturamento[i] < menor) {
            menor = faturamento[i];
        }

        if (faturamento[i] > maior) {
            maior = faturamento[i];
        }

        if (faturamento[i] > media) {
            num_dias_acima_da_media++;
        }
    }

    printf("Menor faturamento: %.2f\n", menor);
    printf("Maior faturamento: %.2f\n", maior);
    printf("Dias acima da média: %d\n", num_dias_acima_da_media);

    return 0;
}

