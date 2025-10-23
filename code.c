#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void numarali_liste_olustur(char *input) {
    printf("\n🛒 MARKET LİSTENİZ:\n");
    printf("-------------------\n");
    
    char *token = strtok(input, ",");
    int sira = 1;
    
    while (token != NULL) {
        // Baştaki ve sondaki boşlukları temizle
        char *bas = token;
        char *son = token + strlen(token) - 1;
        
        while (isspace((unsigned char)*bas)) bas++;
        while (son > bas && isspace((unsigned char)*son)) son--;
        
        *(son + 1) = '\0';
        
        if (strlen(bas) > 0) {
            printf("%2d. ✅ %s\n", sira, bas);
            sira++;
        }
        
        token = strtok(NULL, ",");
    }
    
    printf("-------------------\n");
}

int main() {
    printf("📱 MARKET LİSTESİ UYGULAMASI\n");
    printf("=============================\n\n");
    
    while (1) {
        char input[500];
        
        printf("Virgülle ayırarak ürünleri yazın:\n");
        printf("Örnek: elma, süt, ekmek, yumurta\n");
        printf("Çıkmak için 'q' yazın\n\n");
        printf("➡️  Ürünleriniz: ");
        
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        
        if (strcmp(input, "q") == 0 || strcmp(input, "quit") == 0) {
            printf("👋 Güle güle!\n");
            break;
        }
        
        if (strlen(input) == 0) {
            printf("❌ Boş liste! Tekrar deneyin.\n\n");
            continue;
        }
        
        numarali_liste_olustur(input);
        printf("\n");
    }
    
    return 0;
}