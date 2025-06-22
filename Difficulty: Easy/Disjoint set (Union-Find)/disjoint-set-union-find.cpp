// Function to find the representative (parent) of the set that x belongs to
int find(int par[], int x) {
    if (par[x] != x) {
        par[x] = find(par, par[x]); // Path Compression
    }
    return par[x];
}

// Function to unite two sets x and z
void unionSet(int par[], int x, int z) {
    int x_par = find(par, x);
    int z_par = find(par, z);
    if (x_par != z_par) {
        par[x_par] = z_par; // Union
    }
}
