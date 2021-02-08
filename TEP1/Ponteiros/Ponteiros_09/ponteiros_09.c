void converte (int sec, int *h, int *m, int *s){
    *h = sec / 3600;
    *m = (sec - *h * 3600) / 60;
    *s = (sec - (*m * 60)) - (*h * 3600);
}
