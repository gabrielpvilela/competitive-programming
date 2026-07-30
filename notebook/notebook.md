# 📘 Notebook de Programação Competitiva

## Índice
- [Grafos](#grafos)
- [Matemática](#matemática)
- [Geometria 2D](#geometria-2d)
- [Strings](#strings)
- [Estruturas de Dados](#estruturas-de-dados)
- [Programação Dinâmica](#programação-dinâmica)

---

## Utilidades

### Header
```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```
### Tabela ASCII (32–126)
```
Dec Hex Char | Dec Hex Char | Dec Hex Char | Dec Hex Char
-----------------+-------------------+-------------------+----------------
32 20 (esp) | 48 30 0 | 64 40 @ | 80 50 P
33 21 ! | 49 31 1 | 65 41 A | 81 51 Q
34 22 " | 50 32 2 | 66 42 B | 82 52 R
35 23 # | 51 33 3 | 67 43 C | 83 53 S
36 24 $ | 52 34 4 | 68 44 D | 84 54 T
37 25 % | 53 35 5 | 69 45 E | 85 55 U
38 26 & | 54 36 6 | 70 46 F | 86 56 V
39 27 ' | 55 37 7 | 71 47 G | 87 57 W
40 28 ( | 56 38 8 | 72 48 H | 88 58 X
41 29 ) | 57 39 9 | 73 49 I | 89 59 Y
42 2A * | 58 3A : | 74 4A J | 90 5A Z
43 2B + | 59 3B ; | 75 4B K | 91 5B [
44 2C , | 60 3C < | 76 4C L | 92 5C
45 2D - | 61 3D = | 77 4D M | 93 5D ]
46 2E . | 62 3E > | 78 4E N | 94 5E ^
47 2F / | 63 3F ? | 79 4F O | 95 5F _
-----------------+-------------------+-------------------+----------------
96 60 ` | 112 70 p | 120 78 x |
97 61 a | 113 71 q | 121 79 y |
98 62 b | 114 72 r | 122 7A z |
99 63 c | 115 73 s | 123 7B { |
100 64 d | 116 74 t | 124 7C | |
101 65 e | 117 75 u | 125 7D } |
102 66 f | 118 76 v | 126 7E ~ |
103 67 g | 119 77 w | |
104 68 h | | |
105 69 i | | |
106 6A j | | |
107 6B k | | |
108 6C l | | |
109 6D m | | |
110 6E n | | |
111 6F o | | |
```
### Fórmulas Úteis
---

#### Combinatória

A área de "contagem" é uma das mais importantes em programação competitiva.

* **Permutações:** O número de maneiras de ordenar `n` itens distintos.
    $$P(n) = n!$$

* **Arranjos (Permutações Parciais):** O número de maneiras de escolher e ordenar `k` itens de um total de `n`.
    $$A(n, k) = \frac{n!}{(n-k)!}$$

* **Combinações:** O número de maneiras de escolher `k` itens de um total de `n`, sem se importar com a ordem. É a fórmula mais comum de todas.
    $$C(n, k) = \binom{n}{k} = \frac{n!}{k!(n-k)!}$$
    * **Relação de Stifel (para DP/Triângulo de Pascal):** Útil para calcular combinações em DPs.
        $$\binom{n}{k} = \binom{n-1}{k} + \binom{n-1}{k-1}$$

* **Números de Catalan:** Aparecem em problemas de contagem envolvendo estruturas com restrições recursivas (ex: parênteses balanceados, triangulações de polígonos, árvores binárias).
    $$C_n = \frac{1}{n+1}\binom{2n}{n}$$

* **Bolas e Barras (Stars and Bars):** Usado para encontrar o número de soluções inteiras não-negativas para uma equação.
    * Para a equação $x_1 + x_2 + \dots + x_k = n$:
        $$\binom{n+k-1}{k-1}$$

---
#### Teoria dos Números

Essenciais para problemas envolvendo divisibilidade, primos e aritmética modular.

* **Relação entre MDC e MMC:**
    $$a \cdot b = \text{mdc}(a, b) \cdot \text{mmc}(a, b)$$

* **Inverso Modular (usando o Pequeno Teorema de Fermat):** Usado para calcular $(a / b) \pmod{m}$ quando `m` é um número primo. A divisão vira uma multiplicação pelo inverso modular.
    * Se $m$ é primo, o inverso de $a$ é $a^{-1} \equiv a^{m-2} \pmod{m}$.
    * Isso pode ser calculado com a sua função de exponenciação rápida: `binpow(a, m-2, m)`.

* **Função Totiente de Euler ($\phi(n)$):** Conta a quantidade de números inteiros positivos até `n` que são coprimos com `n`.
    * Se a fatoração em primos de $n$ é $p_1^{k_1} \cdot p_2^{k_2} \cdot \dots$, então:
        $$\phi(n) = n \cdot \left(1 - \frac{1}{p_1}\right) \cdot \left(1 - \frac{1}{p_2}\right) \cdot \dots$$

---
#### Somas Notáveis

* **Soma de elementos em uma PA.**

$S_n = (E_1 + E_{(n-1)}) \cdot \dfrac{n}{2}$

* **Soma de elementos em uma PG.**

$Sn = a_1 \cdot \dfrac{(q^n - 1)}{q - 1}$

Além de PA e PG, estas são muito úteis.

* **Soma dos `n` primeiros quadrados:**
    $$\sum_{i=1}^{n} i^2 = \frac{n(n+1)(2n+1)}{6}$$

* **Soma dos `n` primeiros cubos:**
    $$\sum_{i=1}^{n} i^3 = \left(\frac{n(n+1)}{2}\right)^2$$

---
#### Geometria Computacional

Fórmulas básicas para problemas de geometria.

* **Distância Euclidiana entre dois pontos $(x_1, y_1)$ e $(x_2, y_2)$:**
    $$d = \sqrt{(x_2-x_1)^2 + (y_2-y_1)^2}$$

* **Fórmula de Herão:** Calcula a área de um triângulo a partir do comprimento de seus três lados (`a`, `b`, `c`).
    $$\text{Área} = \sqrt{s(s-a)(s-b)(s-c)}$$
    (Onde $s = \frac{a+b+c}{2}$ é o semiperímetro)
  
## Grafos

### BFS
Busca em largura em **O(V+E)**.
```cpp
// BFS - O(V + E)
vector<vector<int>> adj;   // lista de adjacência

void bfs(int start) {
    queue<int> q;
    vector<bool> visited(GRAPH_MAX_SIZE, false);

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Processa o vértice u aqui, se necessário

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```
### DFS
Busca em Profundidade em **O(V+E)**
```cpp
// DFS - O(V + E)
vector<vector<int>> adj;   // lista de adjacência
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;

    // Processa o vértice u aqui, se necessário

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
```
### UNION FIND (MUDAR DPS PRA LIMPAR CADA ITERAÇÃO)
```cpp
#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100001;
int link[N_MAX];
int size[N_MAX];

// Função para encontrar o representante do conjunto
int find(int x) {
    return (x == link[x]) ? x : (link[x] = find(link[x]));
}

// Função para verificar se dois elementos estão no mesmo conjunto
bool same(int x, int y) {
    return find(x) == find(y);
}

// Função para unir dois conjuntos
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}
//exemplo na main
int main() {

    int N, K, i, x1, x2;
    char op;

    cin >> N >> K;

    // Inicialização da estrutura DSU
    for (i = 0; i < N; ++i) {
        link[i] = i;
        size[i] = 1;
    }

    for (i = 0; i < K; ++i) {
        cin >> op >> x1 >> x2;
        if (op == 'C') {
            if (same(x1, x2)) {
                cout << "S" << '\n';
            } else {
                cout << "N" << '\n';
            }
        } else { // 'U'
            if(!same(x1, x2))unite(x1, x2);
        }
    }

    return 0;
}
```
### DIJKSTRA
Menor caminho com pesos positivos em **O((V+E) log V)**.
```cpp
// DIJKSTRA - O((V + E) log V)
// A lista de adjacência 'adj' deve armazenar pares {vertice, peso}.
vector<int> dijkstra(int s, int n, const vector<vector<pair<int, int>>>& adj) {
    const int INF = 1e9; // Usar um valor grande como infinito
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({0, s}); // Fila de prioridade armazena {distancia, vertice}

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) {
            continue; // Já encontramos um caminho mais curto para 'u'
        }

        for (auto [v, w] : adj[u]) { // Para cada vizinho 'v' de 'u' com peso 'w'
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```
### Algoritmo de Floyd-Warshall (All-Pairs Shortest Path)
Encontra o caminho mais curto entre todos os pares de vértices em um grafo ponderado, usando programação dinâmica. A complexidade é **O(V^3)**, o que o torna ideal para grafos pequenos.
```cpp
#include <bits/stdc++.h>

using namespace std;

// Defina o número máximo de vértices que o problema pode ter.
const int MAXN = 101; 
// Use um valor grande para infinito, mas que evite overflow na soma.
const long long INF = 1e18; 

int n; // Número de vértices
long long dist[MAXN][MAXN];

// Função para inicializar a matriz de adjacência/distâncias
void inicializar_matriz() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
}

// Algoritmo de Floyd-Warshall
void floyd_warshall() {
    // Itera por cada vértice 'k' como um possível intermediário
    for (int k = 0; k < n; k++) {
        // Itera por todas as origens 'i'
        for (int i = 0; i < n; i++) {
            // Itera por todos os destinos 'j'
            for (int j = 0; j < n; j++) {
                // Se k é um intermediário válido (caminhos não infinitos)
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    // Atualiza a distância se o caminho via 'k' for mais curto
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

// Exemplo de uso
int main() {
    // Leitura do número de vértices (n) e arestas (m)
    int m;
    cin >> n >> m;

    inicializar_matriz();

    // Leitura das arestas
    for (int i = 0; i < m; i++) {
        int u, v;
        long long peso;
        cin >> u >> v >> peso;
        // Para grafos com arestas múltiplas, é comum pegar a de menor peso
        dist[u][v] = min(dist[u][v], peso);
        // Se o grafo for não-direcionado, adicione a aresta de volta
        // dist[v][u] = min(dist[v][u], peso);
    }

    // Roda o algoritmo
    floyd_warshall();

    // Agora, dist[i][j] contém a menor distância entre os vértices i e j.
    int origem = 0, destino = n - 1;
    if (dist[origem][destino] == INF) {
        cout << "Nao ha caminho entre " << origem << " e " << destino << endl;
    } else {
        cout << "A menor distancia entre " << origem << " e " << destino << " eh: " << dist[origem][destino] << endl;
    }
    
    // Detecção de ciclo negativo: após rodar o algoritmo, se dist[i][i] < 0
    // para qualquer 'i', então existe um ciclo negativo alcançável a partir de 'i'.

    return 0;
}
```
### Algoritmo de Bellman-Ford (Shortest Path com Pesos Negativos)
Calcula o caminho mais curto de uma única origem (source) para todos os outros vértices em um grafo ponderado. É a principal alternativa ao Dijkstra quando o grafo pode conter arestas com pesos negativos. Sua complexidade é **O(V*E)**, onde V é o número de vértices e E o de arestas.
```cpp
#include <bits/stdc++.h>

using namespace std;

// Defina o número máximo de vértices e um valor seguro para infinito.
const int MAXN = 101;
const long long INF = 1e18;

// Estrutura para representar as arestas do grafo.
// Para o Bellman-Ford, uma lista de arestas é a forma mais fácil de trabalhar.
struct Aresta {
    int u, v; // Vértices de origem e destino
    long long peso;
};

int n; // Número de vértices
vector<long long> dist(MAXN, INF);

// Algoritmo de Bellman-Ford
// Parâmetros: s (origem), arestas (vetor com todas as arestas do grafo)
// Retorna: true se NÃO houver ciclo negativo, false se houver.
// O vetor 'dist' é preenchido com as menores distâncias.
bool bellman_ford(int s, const vector<Aresta>& arestas) {
    // 1. Inicializa as distâncias
    dist.assign(n, INF);
    dist[s] = 0;

    // 2. Relaxa todas as arestas V-1 vezes
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& aresta : arestas) {
            if (dist[aresta.u] != INF && dist[aresta.u] + aresta.peso < dist[aresta.v]) {
                dist[aresta.v] = dist[aresta.u] + aresta.peso;
            }
        }
    }

    // 3. V-ésima iteração para detectar ciclos de peso negativo
    for (const auto& aresta : arestas) {
        if (dist[aresta.u] != INF && dist[aresta.u] + aresta.peso < dist[aresta.v]) {
            // Se uma distância puder ser melhorada, há um ciclo negativo.
            return false;
        }
    }

    return true; // Nenhum ciclo negativo encontrado
}

// Exemplo de uso
int main() {
    int m; // Número de arestas
    cin >> n >> m;

    vector<Aresta> arestas(m);
    for (int i = 0; i < m; ++i) {
        cin >> arestas[i].u >> arestas[i].v >> arestas[i].peso;
    }

    int origem = 0;
    bool sem_ciclo_negativo = bellman_ford(origem, arestas);

    if (!sem_ciclo_negativo) {
        cout << "O grafo contem um ciclo de peso negativo!" << endl;
    } else {
        cout << "Distancias a partir da origem " << origem << ":" << endl;
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INF) {
                cout << "Vertice " << i << ": Nao alcancavel" << endl;
            } else {
                cout << "Vertice " << i << ": " << dist[i] << endl;
            }
        }
    }

    return 0;
}
```
### EDMONDS-KARP
Calcula o fluxo máximo em um grafo. A complexidade é **O(V * E²)**.
```cpp
// Edmonds-Karp - O(V * E^2)
const int MAX = 110; // Número máximo de vértices
const long long INF = 1e18;

int n; // Número de vértices
long long capacity[MAX][MAX];
vector<int> adj[MAX];

// Encontra um caminho de aumento usando BFS
long long bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, long long>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int u = q.front().first;
        long long flow = q.front().second;
        q.pop();

        for (int v : adj[u]) {
            if (parent[v] == -1 && capacity[u][v] > 0) {
                parent[v] = u;
                long long new_flow = min(flow, capacity[u][v]);
                if (v == t) {
                    return new_flow;
                }
                q.push({v, new_flow});
            }
        }
    }
    return 0; // Nenhum caminho de aumento encontrado
}

// Função principal do Edmonds-Karp
long long edmonds_karp(int s, int t) {
    long long max_flow = 0;
    vector<int> parent(n + 1);
    long long new_flow;

    // Enquanto houver um caminho de aumento
    while ((new_flow = bfs(s, t, parent)) > 0) {
        max_flow += new_flow;
        int current = t;
        while (current != s) {
            int prev = parent[current];
            // Atualiza capacidades no grafo residual
            capacity[prev][current] -= new_flow;
            capacity[current][prev] += new_flow;
            current = prev;
        }
    }
    return max_flow;
}

// Para usar:
// 1. Defina 'n' (número de vértices).
// 2. Preencha a matriz 'capacity' e a lista 'adj'.
//    Para arestas bidirecionais, adicione capacidade em ambos os sentidos.
// 3. Chame edmonds_karp(source, sink).
// 4. Lembre-se de limpar as estruturas (capacity, adj) para múltiplos casos de teste.
```
### Dinic 
Algoritmo pra fluxos máximos mais eficiente.
```cpp
// Dinic

// Complexity: O (V ^ 2 * E)
//
// Special Cases:
// Unit Capacities: O (min (V ^ 2/3, E ^ 1/2) * E)
// Bipartite Matching: O (sqrt (V) * E)
const int MAXV = 512;

struct Edge {
    int to, cap;
    Edge(int a, int b) { to = a; cap = b; }
};

vector<int> adj[MAXV];
vector<Edge> edges;
int ptr[MAXV], dinic_dist[MAXV];

inline void addEdge(int u, int v, int cap) {
    adj[u].push_back(edges.size());
    edges.push_back(Edge(v, cap));
    adj[v].push_back(edges.size());
    edges.push_back(Edge(u, 0));
}

bool dinic_bfs(int _s, int _t) {
    memset(dinic_dist, -1, sizeof dinic_dist);
    dinic_dist[_s] = 0;
    queue<int> q;
    q.push(_s);

    while (!q.empty() && dinic_dist[_t] == -1) {
        int v = q.front();
        q.pop();
        for (int a = 0; a < adj[v].size(); ++a) {
            int ind = adj[v][a];
            int nxt = edges[ind].to;
            if (dinic_dist[nxt] == -1 && edges[ind].cap) {
                dinic_dist[nxt] = dinic_dist[v] + 1;
                q.push(nxt);
            }
        }
    }

    return dinic_dist[_t] != -1;
}

int dinic_dfs(int v, int _t, int flow) {
    if (v == _t) return flow;
    for (int &a = ptr[v]; a < (int) adj[v].size(); ++a) {
        int ind = adj[v][a];
        int nxt = edges[ind].to;
        if (dinic_dist[nxt] == dinic_dist[v] + 1 && edges[ind].cap) {
            int got = dinic_dfs(nxt, _t, min(flow, edges[ind].cap));
            if (got) {
                edges[ind].cap -= got;
                edges[ind ^ 1].cap += got;
                return got;
            }
        }
    }

    return 0;
}

int dinic(int _s, int _t) {
    int ret = 0, got;
    while (dinic_bfs(_s, _t)) {
        memset(ptr, 0, sizeof ptr);
        while ((got = dinic_dfs(_s, _t, 0x3F3F3F3F))) ret += got;
    }

    return ret;
}

inline void dinic_clear() {
    for (int a = 0; a < MAXV; ++a) adj[a].clear();
    edges.clear();
}
```
### Componentes Fortemente Conexos (Kosaraju)
O algoritmo de Kosaraju decompõe um grafo direcionado em seus componentes fortemente conexos (SCCs). A complexidade é **O(V+E)**.
```cpp
// Componentes Fortemente Conexos (Kosaraju) - O(V + E)

// 'visitado' rastreia os vértices que já foram visitados na DFS atual.
vector<bool> visitado;

// Executa uma busca em profundidade a partir do vértice v.
// Cada vértice visitado é adicionado ao vetor 'saida' quando a DFS o deixa (pós-ordem).
void dfs(int v, const vector<vector<int>>& adj, vector<int>& saida) {
    visitado[v] = true;
    for (int u : adj[v]) {
        if (!visitado[u]) {
            dfs(u, adj, saida);
        }
    }
    saida.push_back(v);
}

// entrada: adj -- lista de adjacência do grafo G
// saida: componentes -- os componentes fortemente conexos de G
// saida: adj_condensado -- lista de adjacência do grafo de condensação G^SCC
void encontrar_sccs(const vector<vector<int>>& adj,
                    vector<vector<int>>& componentes,
                    vector<vector<int>>& adj_condensado) {
    int n = adj.size();
    componentes.clear();
    adj_condensado.clear();

    // 'ordem' será uma lista dos vértices de G ordenados pelo tempo de finalização.
    vector<int> ordem;
    visitado.assign(n, false);

    // Primeira série de buscas em profundidade no grafo original.
    for (int i = 0; i < n; i++) {
        if (!visitado[i]) {
            dfs(i, adj, ordem);
        }
    }

    // Cria a lista de adjacência do grafo transposto (G^T).
    vector<vector<int>> adj_reverso(n);
    for (int v = 0; v < n; v++) {
        for (int u : adj[v]) {
            adj_reverso[u].push_back(v);
        }
    }

    visitado.assign(n, false);
    reverse(ordem.begin(), ordem.end());

    // 'raiz_componente' indica o vértice raiz do SCC de um determinado vértice.
    vector<int> raiz_componente(n);

    // Segunda série de buscas em profundidade, no grafo transposto.
    for (int v : ordem) {
        if (!visitado[v]) {
            vector<int> componente_atual;
            dfs(v, adj_reverso, componente_atual);
            
            componentes.push_back(componente_atual);
            int raiz = componente_atual[0];
            for (int u : componente_atual) {
                raiz_componente[u] = raiz;
            }
        }
    }

    // Adiciona as arestas ao grafo de condensação.
    adj_condensado.assign(n, {});
    for (int v = 0; v < n; v++) {
        for (int u : adj[v]) {
            if (raiz_componente[v] != raiz_componente[u]) {
                adj_condensado[raiz_componente[v]].push_back(raiz_componente[u]);
            }
        }
    }
}
```
### Algoritmo de Kruskal (Minimum Spanning Tree)
A verificação de ciclos é feita de forma eficiente com uma estrutura Union-Find (DSU). A complexidade final do algoritmo é dominada pela ordenação das arestas: **O(E logE)**.
```cpp
#include <bits/stdc++.h>

using namespace std;

// Estrutura para representar uma aresta ponderada
struct Aresta {
    int u, v, peso;

    // Operador para permitir a ordenação das arestas pelo peso
    bool operator<(const Aresta& other) const {
        return peso < other.peso;
    }
};

// --- Estrutura Union-Find (DSU) ---
vector<int> pai;
vector<int> tamanho;

// Encontra o representante do conjunto de 'i' com compressão de caminho
int find(int i) {
    if (pai[i] == i) {
        return i;
    }
    return pai[i] = find(pai[i]);
}

// Une os conjuntos de 'a' e 'b' por tamanho
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (tamanho[a] < tamanho[b]) {
            swap(a, b);
        }
        pai[b] = a;
        tamanho[a] += tamanho[b];
    }
}
// --- Fim da Estrutura Union-Find ---


// Função principal do Algoritmo de Kruskal
long long kruskal(int n, vector<Aresta>& arestas) {
    // Inicializa a estrutura Union-Find
    pai.resize(n);
    iota(pai.begin(), pai.end(), 0); // Preenche pai[i] = i
    tamanho.assign(n, 1);

    // 1. Ordena todas as arestas pelo peso
    sort(arestas.begin(), arestas.end());

    long long custo_total = 0;
    vector<Aresta> mst_arestas;

    // 2. Percorre as arestas ordenadas
    for (const auto& aresta : arestas) {
        // 3. Verifica se os vértices da aresta estão em componentes diferentes
        if (find(aresta.u) != find(aresta.v)) {
            // Se sim, a aresta não forma um ciclo
            custo_total += aresta.peso;
            mst_arestas.push_back(aresta);
            unite(aresta.u, aresta.v);
        }
    }

    // Opcional: Verificar se uma MST foi formada (todos os vértices conectados)
    // if (mst_arestas.size() != n - 1) {
    //     return -1; // Grafo não é conexo
    // }

    return custo_total;
}
```

## Matemática

### MDC - Máximo Divisor Comum (GCD)
O Algoritmo de Euclides é o método mais eficiente para encontrar o maior divisor comum entre dois números. A complexidade é **O(log(min(a,b)))**.
```cpp
// MDC - Algoritmo de Euclides - O(log(min(a, b)))
int gcd(int a, int b) {
    while (b) {
        a %= b;
        // Troca os valores de a e b
        int temp = a;
        a = b;
        b = temp;
    }
    return a;
}
```
### MMC - Mínimo Múltiplo Comum (LCM)
```cpp
int lmc(int m, int n){
    return (m * n) / gcd(m, n);
}
```
### Inverso Modular
Inverso modular para quando o a e m são coprimos
```cpp
int mod_inv(int a, int m) {
    if (a <= 1) return a;
    return m - (long long)(m / a) * mod_inv(m % a, m) % m;
}
```
Inverso modular para quando o m é primo (Mais Usado)
```cpp
int mod_pow(long long a, long long e, int m) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = res * a % m;
        a = a * a % m;
        e >>= 1;
    }
    return res;
}
int mod_inv_prime(int a, int m) {
    return mod_pow(a, m - 2, m);
}
```
### Conversão de Bases Numéricas
#### De Decimal (Base 10) para Base B
Usa o método de divisões sucessivas. O resultado é uma string, pois pode conter caracteres (ex: 'A', 'F' para hexadecimal).
```cpp
#include <bits/stdc++.h>

using namespace std;

// Converte um número 'n' da base 10 para uma base 'b' (2 <= b <= 36).
string from_decimal(long long n, int b) {
    if (n == 0) {
        return "0";
    }
    
    string result = "";
    while (n > 0) {
        int remainder = n % b;
        if (remainder < 10) {
            // Converte o resto numérico para seu caractere '0'-'9'
            result += to_string(remainder);
        } else {
            // Converte o resto numérico para seu caractere 'A'-'Z'
            result += (char)('A' + (remainder - 10));
        }
        n /= b;
    }
    
    // Os restos foram coletados na ordem inversa, então revertemos a string.
    reverse(result.begin(), result.end());
    return result;
}
```
#### De Base B para Decimal (Base 10)
```cpp
#include <bits/stdc++.h>

using namespace std;

// Converte uma string 'num' na base 'b' para a base 10 (decimal).
long long to_decimal(const string& num, int b) {
    long long result = 0;
    long long power = 1;

    // Itera pela string da direita para a esquerda.
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit_value;
        if (num[i] >= '0' && num[i] <= '9') {
            digit_value = num[i] - '0';
        } else {
            digit_value = num[i] - 'A' + 10;
        }

        if (digit_value >= b) {
            // Dígito inválido para a base fornecida.
            // Você pode tratar o erro aqui (ex: retornar -1).
            return -1; 
        }

        result += digit_value * power;
        power *= b;
    }
    return result;
}
```
### CRIVO DE ERATÓSTENES
É um algoritmo altamente eficiente para encontrar todos os números primos até um determinado limite N. Sua complexidade de tempo é **O(N log logN)**
```cpp
#include <bits/stdc++.h>

using namespace std;

// Define o limite máximo para o crivo.
// Em problemas, ajuste para o maior valor necessário.
const int MAXN = 1000001; 

// Vetor booleano global para armazenar a primalidade.
// is_prime[i] = true se i for primo, false caso contrário.
vector<bool> is_prime(MAXN, true);

// Função que implementa o Crivo de Eratóstenes.
// Preenche o vetor is_prime em O(N log log N).
void sieve() {
    // 1. Marcar 0 e 1 como não-primos
    is_prime[0] = is_prime[1] = false;

    // 2. Iterar a partir de p=2
    // A iteração vai até p*p < MAXN, pois qualquer número composto
    // n terá um fator primo <= sqrt(n).
    for (int p = 2; p * p < MAXN; p++) {
        // 3. Se p ainda não foi marcado, ele é primo
        if (is_prime[p]) {
            // 4. Marca todos os múltiplos de p como não-primos
            // Otimização: começamos a marcar de p*p, pois os múltiplos
            // menores (2*p, 3*p, etc.) já foram marcados por primos menores.
            for (int i = p * p; i < MAXN; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

// Exemplo de uso
int main() {
    // Pré-computa todos os primos até MAXN.
    // Chame esta função uma vez no início do seu código.
    sieve();

    // Agora, verificar se um número é primo é uma consulta O(1).
    cout << "37 eh primo? " << (is_prime[37] ? "Sim" : "Nao") << endl;
    cout << "100 eh primo? " << (is_prime[100] ? "Sim" : "Nao") << endl;

    // O código da imagem lia A e B e contava os primos no intervalo.
    // Com o crivo, isso se torna trivial:
    int A = 1, B = 100;
    int count = 0;
    for (int i = A; i <= B; ++i) {
        if (is_prime[i]) {
            count++;
        }
    }
    cout << "Existem " << count << " primos entre " << A << " e " << B << "." << endl;

    return 0;
}
```
### Encontrar Todos os Divisores
Para encontrar todos os divisores de um número N, podemos iterar de 1 até sqrtN. Se i divide N, então N/i também é um divisor. Essa abordagem tem complexidade **O(sqrtN)**
```cpp
#include <bits/stdc++.h>

using namespace std;

// Encontra todos os divisores de 'n' em O(sqrt(n)).
vector<long long> encontrar_divisores(long long n) {
    vector<long long> divisores;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisores.push_back(i);
            // Evita adicionar a raiz quadrada duas vezes se 'n' for um quadrado perfeito.
            if (i * i != n) {
                divisores.push_back(n / i);
            }
        }
    }
    // Opcional: ordena os divisores para uma saída mais limpa.
    sort(divisores.begin(), divisores.end());
    return divisores;
}
```
### FIBONACCI
Fibonacci iterativo (para n pequenos)
```cpp
long long fib_iterativo(int n) {
    if (n <= 1) {
        return n;
    }
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
```
Fibonacci com Exponenciação de Matriz (para n grandes como 10^18)
```cpp
#include <vector>

// Fibonacci com Exponenciação de Matriz - O(log n)
// Ideal para N grande e com resultado modular.

// Define um tipo 'matrix' para facilitar a leitura do código.
using matrix = std::vector<std::vector<long long>>;

// Define o módulo para os cálculos. Mude se o problema pedir outro.
const int MOD = 1e9 + 7;

// Função para multiplicar duas matrizes 2x2 sob um módulo.
matrix multiply(const matrix& A, const matrix& B) {
    matrix C = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Função para elevar uma matriz a uma potência (exponenciação rápida).
matrix matrix_pow(matrix A, long long p) {
    matrix res = {{1, 0}, {0, 1}}; // Matriz identidade

    while (p > 0) {
        if (p & 1) { // Se p for ímpar
            res = multiply(res, A);
        }
        A = multiply(A, A);
        p >>= 1; // p = p / 2
    }
    return res;
}

// Função principal para encontrar o N-ésimo número de Fibonacci.
long long fib(long long n) {
    if (n == 0) {
        return 0;
    }

    // Matriz de transformação de Fibonacci.
    matrix T = {{1, 1}, {1, 0}};
    
    // Calcula T^n. De acordo com a fórmula, o resultado F(n)
    // estará na posição [0][1] da matriz resultante.
    T = matrix_pow(T, n);
    
    return T[0][1];
}

/*
// Exemplo de uso na main:
int main() {
    long long n;
    std::cin >> n;
    std::cout << fib(n) << std::endl;
    return 0;
}
*/
```
### FAST POW
Exponenciação Rápida (Binária)
Calcula (a^b)%m de forma eficiente. A complexidade é **O(logb)**.

Esta é a versão modular, ideal para problemas que pedem o resultado sob um módulo (como 10^9 +7) para evitar que os números fiquem grandes demais (overflow). Se um problema pedir apenas o cálculo de a^b e o resultado couber em um long long, basta adaptar a função removendo o parâmetro m e todas as operações de módulo (%).
```cpp
// Exponenciação Rápida (Binária) - O(log b)
// Versão para cálculo modular: (a^b) % m
long long binpow(long long a, long long b, long long m) {
    // A linha abaixo é importante caso 'a' seja maior que 'm'.
    // Se o problema pedir um módulo, é sempre bom garantir
    // que os números manipulados permaneçam pequenos.
    a %= m;
    
    long long res = 1;
    while (b > 0) {
        // Se o bit menos significativo de b for 1 (ou seja, b é ímpar)
        if (b & 1)
            // Multiplica o resultado por 'a' e aplica o módulo
            // para manter o número dentro do limite.
            res = (res * a) % m;
        
        // Eleva 'a' ao quadrado e aplica o módulo.
        // Isso evita que 'a' cresça excessivamente.
        a = (a * a) % m;
        
        b >>= 1; // b = b / 2
    }
    return res;
}

```
### Eliminação Gaussiana (Sistemas de Equações Lineares)
Um algoritmo clássico da álgebra linear para resolver sistemas de equações lineares da forma Ax=b. Ele é adequado para sistemas pequenos devido à sua complexidade **O(N^3)**.
```cpp
#include <bits/stdc++.h>

using namespace std;

// É crucial usar uma tolerância (EPS) para comparar doubles.
const double EPS = 1e-9;

// Função para resolver um sistema de N equações lineares com N variáveis.
// Recebe a matriz aumentada mat[N][N+1].
// Retorna um vetor com a solução. Se não houver solução única, retorna um vetor vazio.
vector<double> eliminacao_gaussiana(vector<vector<double>>& mat) {
    int n = mat.size();

    // --- Fase 1: Eliminação Progressiva com Pivoteamento Parcial ---
    for (int i = 0; i < n; i++) {
        // 1. Pivoteamento: Encontrar a linha com o maior pivô na coluna 'i'
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(mat[k][i]) > abs(mat[max_row][i])) {
                max_row = k;
            }
        }
        swap(mat[i], mat[max_row]);

        // 2. Verificar se o sistema tem solução única.
        // Se o maior pivô for próximo de zero, a matriz é singular.
        if (abs(mat[i][i]) < EPS) {
            // Não há solução única (pode ter 0 ou infinitas soluções).
            return {}; 
        }

        // 3. Zerar os elementos abaixo do pivô na coluna 'i'
        for (int k = i + 1; k < n; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i; j < n + 1; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    // --- Fase 2: Substituição Reversa ---
    vector<double> sol(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += mat[i][j] * sol[j];
        }
        sol[i] = (mat[i][n] - sum) / mat[i][i];
    }
    
    return sol;
}

// Exemplo de uso
int main() {
    // Exemplo: Resolver o sistema
    // 2x + y - z = 8
    // -3x - y + 2z = -11
    // -2x + y + 2z = -3
    // Solução é x=2, y=3, z=-1

    int n = 3;
    // Matriz aumentada [A|b]
    vector<vector<double>> mat = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    vector<double> solucao = eliminacao_gaussiana(mat);

    if (solucao.empty()) {
        cout << "O sistema nao possui solucao unica." << endl;
    } else {
        cout << "Solucao:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "x" << i << " = " << solucao[i] << endl;
        }
    }

    return 0;
}
```
### Funções extras com Gauss
```cpp
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
using matrix = vector<vector<double>>;

// --- Motor da Eliminação Gaussiana com Pivoteamento Parcial ---
// Transforma a matriz 'mat' em sua forma escalonada (triangular superior).
// Retorna o número de trocas de linha realizadas.
int gaussian_elimination_engine(matrix& mat) {
    int n = mat.size();
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(mat[k][i]) > abs(mat[max_row][i])) {
                max_row = k;
            }
        }
        if (i != max_row) {
            swap(mat[i], mat[max_row]);
            swaps++;
        }

        if (abs(mat[i][i]) < EPS) continue; // Matriz singular, mas continuamos

        for (int k = i + 1; k < n; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i; j < mat[0].size(); j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }
    return swaps;
}

// --- Aplicação 1: Calculando o Determinante ---
double determinant(matrix mat) {
    if (mat.size() != mat[0].size()) return 0; // Não é matriz quadrada
    int n = mat.size();
    int swaps = gaussian_elimination_engine(mat);
    
    double det = 1.0;
    for (int i = 0; i < n; i++) {
        det *= mat[i][i];
    }
    
    return (swaps % 2 == 1) ? -det : det;
}

// --- Aplicação 2: Encontrando a Matriz Inversa ---
// Retorna a matriz inversa ou uma matriz vazia se não for invertível.
matrix inverse_matrix(matrix mat) {
    if (mat.size() != mat[0].size()) return {}; // Não é matriz quadrada
    int n = mat.size();

    // Cria a matriz aumentada [A | I]
    matrix augmented(n, vector<double>(2 * n));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) augmented[i][j] = mat[i][j];
        augmented[i][i+n] = 1;
    }

    gaussian_elimination_engine(augmented);

    if (abs(augmented[n-1][n-1]) < EPS) return {}; // Não é invertível

    // Fase de eliminação para zerar a parte de CIMA da diagonal (Gauss-Jordan)
    for (int i = n - 1; i >= 0; i--) {
        for (int k = i - 1; k >= 0; k--) {
            double factor = augmented[k][i] / augmented[i][i];
            for (int j = i; j < 2 * n; j++) {
                augmented[k][j] -= factor * augmented[i][j];
            }
        }
    }

    // Transforma a parte esquerda em identidade e extrai a inversa
    matrix inv(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        double divisor = augmented[i][i];
        for (int j = 0; j < n; j++) {
            inv[i][j] = augmented[i][j + n] / divisor;
        }
    }
    return inv;
}

// --- Aplicação 3: Resolvendo Sistemas (como na versão anterior) ---
// O código da versão anterior para resolver sistemas continua válido.
// A função `eliminacao_gaussiana` que montamos já faz o trabalho completo.
vector<double> solve_system(matrix mat) {
    int n = mat.size();
    gaussian_elimination_engine(mat);

    // Verificar se há solução (última linha não pode ser [0 ... 0 | c!=0])
    if (abs(mat[n-1][n-1]) < EPS && abs(mat[n-1][n]) > EPS) return {}; // Sem solução

    // Verificar se há infinitas soluções (última linha é [0 ... 0 | 0])
    // Este caso é mais complexo, aqui retornamos apenas o caso de solução única.
    if (abs(mat[n-1][n-1]) < EPS && abs(mat[n-1][n]) < EPS) return {}; // Infinitas soluções (simplificado)

    vector<double> sol(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += mat[i][j] * sol[j];
        }
        sol[i] = (mat[i][n] - sum) / mat[i][i];
    }
    return sol;
}
```

## Geometria 2D

### Template Básico para Geometria 2D (Gemini)
```cpp
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

const double PI = 2*acos(0);
const double EPS = 1e-10;

// --- Estruturas e Primitivas Base ---

// Função de Comparação segura para doubles
inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// Estrutura de dados para Ponto ou Vetor
struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}

    point operator+(point q) const { return point(x + q.x, y + q.y); }
    point operator-(point q) const { return point(x - q.x, y - q.y); }
    point operator*(double t) const { return point(x * t, y * t); }
    point operator/(double t) const { return point(x / t, y / t); }
    double operator*(point q) const { return x * q.x + y * q.y; } // Produto Escalar (dot)
    double operator%(point q) const { return x * q.y - y * q.x; } // Produto Vetorial (cross)

    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
    bool operator==(point q) const { return cmp(q) == 0; }
    bool operator!=(point q) const { return cmp(q) != 0; }
    bool operator<(point q) const { return cmp(q) < 0; }

    friend ostream& operator<<(ostream& o, point p) {
        return o << "(" << p.x << ", " << p.y << ")";
    }
    static point pivot;
};
point point::pivot;

double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

// --- Funções Geométricas ---

int ccw(point p, point q, point r) {
    return cmp((q - p) % (r - p));
}

bool on_segment(point p, point a, point b) {
    return ccw(a, b, p) == 0 && cmp((a - p) * (b - p)) <= 0;
}

bool intersect(point a, point b, point c, point d) {
    int o1 = ccw(c, d, a), o2 = ccw(c, d, b);
    int o3 = ccw(a, b, c), o4 = ccw(a, b, d);
    if (o1 * o2 < 0 && o3 * o4 < 0) return true;
    if (on_segment(c, a, d) && o1 == 0) return true;
    if (on_segment(b, c, d) && o2 == 0) return true;
    if (on_segment(a, c, d) && o3 == 0) return true;
    if (on_segment(b, c, d) && o4 == 0) return true;
    return false;
}

double dist_point_segment(point p, point a, point b) {
    if (cmp((p - a) * (b - a)) <= 0) return abs(p - a);
    if (cmp((p - b) * (a - b)) <= 0) return abs(p - b);
    return fabs((b - a) % (p - a)) / abs(b - a);
}

double angulo(point p, point q, point r) {
    point u = p - q;
    point v = r - q;
    return atan2(u % v, u * v);
}

// --- Estrutura para Retas (ax + by + c = 0) ---
struct Reta {
    double a, b, c;
    Reta(point p, point q) { a = p.y - q.y; b = q.x - p.x; c = p % q; }
    Reta perpendicular(point p) const { return Reta(-b, a, b * p.x - a * p.y); }
    double eval(point p) const { return a * p.x + b * p.y + c; }
    double dist(point p) const { return fabs(eval(p)) / hypot(a, b); }
    bool operator||(const Reta& r) const { return cmp(a * r.b - b * r.a) == 0; }
    bool operator==(const Reta& r) const { return (*this || r) && cmp(a*r.c - c*r.a) == 0 && cmp(b*r.c-c*r.b)==0; }
    point operator^(const Reta& r) const {
        double det = a * r.b - b * r.a;
        return point((b * r.c - c * r.b) / det, (c * r.a - a * r.c) / det);
    }
private:
    Reta(double a, double b, double c) : a(a), b(b), c(c) {}
};

// --- Estrutura para Círculos ---
struct Circle {
    point o;
    long double r;
    Circle() {}
    Circle(point _o, long double _r) : o(_o), r(_r) {}
    Circle(point a, point b) { o = (a + b) / 2.0; r = abs(o - a); }
    Circle(point a, point b, point c) {
        Reta mediatriz_ab = Reta(a, b).perpendicular((a + b) / 2.0);
        Reta mediatriz_bc = Reta(b, c).perpendicular((b + c) / 2.0);
        if (mediatriz_ab || mediatriz_bc) { o = point(HUGE_VAL, HUGE_VAL); r = -1.0; }
        else { o = mediatriz_ab ^ mediatriz_bc; r = abs(o - a); }
    }
    bool contains(point p) const { return cmp(abs(o - p), r) <= 0; }
    long double getIntersectionArea(const Circle& c) const {
        long double d = abs(o - c.o);
        if (cmp(d, r + c.r) >= 0) return 0.0;
        if (cmp(d, abs(r - c.r)) <= 0) { long double min_r = min(r, c.r); return PI * min_r * min_r; }
        long double ang1 = acos((d*d + r*r - c.r*c.r) / (2*d*r));
        long double ang2 = acos((d*d + c.r*c.r - r*r) / (2*d*c.r));
        long double seg1 = r*r * (ang1 - 0.5 * sin(2*ang1));
        long double seg2 = c.r*c.r * (ang2 - 0.5 * sin(2*ang2));
        return seg1 + seg2;
    }
};

// --- Funções para Polígonos ---
using polygon = vector<point>;

double area_triangulo(point p, point q, point r) {
    return fabs((q - p) % (r - p)) / 2.0;
}

double area_poligono(const polygon& poly) {
    double area_duplicada = 0.0;
    int n = poly.size();
    if (n < 3) return 0.0;
    for (int i = 0; i < n; i++) {
        area_duplicada += poly[i] % poly[(i + 1) % n];
    }
    return fabs(area_duplicada) / 2.0;
}

// Retorna: 2 se DENTRO, 1 se NA BORDA, 0 se FORA.
int ponto_em_poligono(const polygon& poly, point p) {
    if (poly.size() < 3) return 0;
    double total_angle = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        point p1 = poly[i], p2 = poly[(i + 1) % n];
        if (ccw(p1, p2, p) == 0 && on_segment(p, p1, p2)) return 1;
        total_angle += atan2((p1 - p) % (p2 - p), (p1 - p) * (p2 - p));
    }
    return cmp(abs(total_angle), PI) > 0 ? 2 : 0;
}

// --- Fecho Convexo (Convex Hull) ---
bool cmp_polar(point a, point b) {
    int order = ccw(point::pivot, a, b);
    if (order == 0) return cmp(abs(a - point::pivot), abs(b - point::pivot)) < 0;
    return order > 0;
}

void fecho_convexo(vector<point>& pts, bool include_collinear = false) {
    if (pts.size() <= 2) return;
    int pivot_idx = 0;
    for (int i = 1; i < pts.size(); i++) {
        if (cmp(pts[i].y, pts[pivot_idx].y) < 0 || 
           (cmp(pts[i].y, pts[pivot_idx].y) == 0 && cmp(pts[i].x, pts[pivot_idx].x) < 0)) {
            pivot_idx = i;
        }
    }
    swap(pts[0], pts[pivot_idx]);
    point::pivot = pts[0];
    sort(pts.begin() + 1, pts.end(), cmp_polar);
    if (include_collinear) {
        int i = (int)pts.size() - 1;
        while (i > 0 && ccw(point::pivot, pts[i], pts.back()) == 0) i--;
        reverse(pts.begin() + i + 1, pts.end());
    }
    vector<point> hull;
    for (const auto& p : pts) {
        while (hull.size() > 1) {
            int decision = ccw(hull[hull.size() - 2], hull.back(), p);
            if (decision < 0 || (decision == 0 && !include_collinear)) {
                hull.pop_back();
            } else { break; }
        }
        hull.push_back(p);
    }
    pts = hull;
}
```
### Template Básico para Geometria 2D
```cpp
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

const double PI = 2*acos(0);
const double EPS = 1e-10;

// Função de Comparação segura para doubles
inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// Estrutura de dados para Ponto ou Vetor
struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}

    point operator+(point q) const { return point(x + q.x, y + q.y); }
    point operator-(point q) const { return point(x - q.x, y - q.y); }
    point operator*(double t) const { return point(x * t, y * t); }
    point operator/(double t) const { return point(x / t, y / t); }
    double operator*(point q) const { return x * q.x + y * q.y; } // Produto Escalar (dot)
    double operator%(point q) const { return x * q.y - y * q.x; } // Produto Vetorial (cross)

    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
    bool operator==(point q) const { return cmp(q) == 0; }
    bool operator!=(point q) const { return cmp(q) != 0; }
    bool operator<(point q) const { return cmp(q) < 0; }

    friend ostream& operator<<(ostream& o, point p) {
        return o << "(" << p.x << ", " << p.y << ")";
    }
    static point pivot;
};
point point::pivot;

double abs(point p) { return hypot(p.x, p.y); } // Magnitude do vetor
double arg(point p) { return atan2(p.y, p.x); } // Ângulo em radianos

// --- Funções Geométricas Primitivas ---

// Testa a orientação de 3 pontos.
// Pense em uma caminhada do ponto 'p' para o ponto 'q'. A função
// determina de que lado o ponto 'r' está em relação a essa trajetória.
// Retorna:
//   +1: 'r' está à esquerda da linha orientada p->q (curva anti-horária)
//   -1: 'r' está à direita da linha orientada p->q (curva horária)
//    0: 'r', 'p' e 'q' são colineares (estão na mesma linha)
int ccw(point p, point q, point r) {
    return cmp((q - p) % (r - p));
}

// Verifica se o ponto p está no segmento de reta [a, b]
// Pré-condição: a, b, e p devem ser colineares.
bool on_segment(point p, point a, point b) {
    return cmp((a - p) * (b - p)) <= 0;
}

// Interseção de Segmentos de Reta
// Verifica se o segmento [a,b] cruza com o segmento [c,d]
bool intersect(point a, point b, point c, point d) {
    int o1 = ccw(c, d, a), o2 = ccw(c, d, b);
    int o3 = ccw(a, b, c), o4 = ccw(a, b, d);
    if (o1 * o2 < 0 && o3 * o4 < 0) return true;
    if (on_segment(a, c, d) && o1 == 0) return true;
    if (on_segment(b, c, d) && o2 == 0) return true;
    if (on_segment(c, a, b) && o3 == 0) return true;
    if (on_segment(d, a, b) && o4 == 0) return true;
    return false;
}

// Distância de um ponto 'p' a um segmento de reta [a, b]
double dist_point_segment(point p, point a, point b) {
    if (cmp((p - a) * (b - a)) <= 0) return abs(p - a);
    if (cmp((p - b) * (a - b)) <= 0) return abs(p - b);
    return fabs((b - a) % (p - a)) / abs(b - a);
}

//calculando area triangulo com 3 pontos
double area_triangulo(point p, point q, point r) {
    return fabs((q - p) % (r - p)) / 2.0;
}

// --- Funções para Polígonos ---
using polygon = vector<point>;
// adicionar o poligono que ta embaixo na função da area;
// Verifica se um ponto está dentro, na borda ou fora de um polígono.
// Retorna: 2 se DENTRO, 1 se NA BORDA, 0 se FORA.
int ponto_em_poligono(const polygon& poly, point p) {
    if (poly.size() < 3) return 0; // Não é um polígono válido

    double total_angle = 0;
    int n = poly.size();

    for (int i = 0; i < n; i++) {
        point p1 = poly[i];
        point p2 = poly[(i + 1) % n];

        // Primeiro, verifica se o ponto está sobre a aresta atual
        if (ccw(p1, p2, p) == 0 && on_segment(p, p1, p2)) {
            return 1; // NA BORDA
        }

        // Soma o ângulo sinalizado formado por p e a aresta p1-p2
        total_angle += atan2((p1 - p) % (p2 - p), (p1 - p) * (p2 - p));
    }

    // Compara o valor absoluto do ângulo total com PI.
    // Se for próximo de 2*PI, está dentro. Se for próximo de 0, está fora.
    // cmp(abs(total_angle), PI) > 0 verifica se |total_angle| > PI.
    return cmp(abs(total_angle), PI) > 0 ? 2 : 0;
}


// --- Estrutura para Retas (ax + by + c = 0) ---

struct Reta {
    double a, b, c;

    // Construtor a partir de dois pontos
    Reta(point p, point q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p % q;
    }

    // Avalia a equação da reta para um ponto p (eval(p) == 0 quer dizer que ta na reta o ponto)
    double eval(point p) const { return a * p.x + b * p.y + c; }

    // Distância de um ponto p à reta (infinita)
    double dist(point p) const { return fabs(eval(p)) / hypot(a, b); }

    // Retorna uma reta perpendicular que passa por p
    Reta perpendicular(point p) const {
        return Reta(-b, a, b * p.x - a * p.y);
    }

    // --- Operadores ---

    // Verifica se esta reta é paralela à reta 'r'
    bool operator||(const Reta& r) const {
        return cmp(a * r.b - b * r.a) == 0;
    }

    // Verifica se esta reta é igual (coincidente) à reta 'r'
    bool operator==(const Reta& r) const {
        return (*this || r) && cmp(a * r.c - c * r.a) == 0 && cmp(b * r.c - c * r.b) == 0;
    }

    // Retorna o ponto de interseção com a reta 'r'
    // PRECONDIÇÃO: As retas NÃO devem ser paralelas (verifique com || antes).
    point operator^(const Reta& r) const {
        double det = a * r.b - b * r.a;
        return point((b * r.c - c * r.b) / det, (c * r.a - a * r.c) / det);
    }

private:
    // Construtor privado para uso interno (ex: no método perpendicular)
    Reta(double a, double b, double c) : a(a), b(b), c(c) {}
};


// --- Estrutura para Círculos ---

struct Circle {
    point o;
    long double r;

    Circle() {}
    Circle(point _o, long double _r) : o(_o), r(_r) {}

    // Círculo cujo diâmetro é o segmento AB
    Circle(point a, point b) {
        o = (a + b) / 2.0;
        r = abs(o - a);
    }

    // Círculo que passa por três pontos (circuncírculo do triângulo ABC)
    Circle(point a, point b, point c) {
        // Encontra o ponto de interseção das mediatrizes de AB e BC
        Reta ab(a, b);
        Reta bc(b, c);
        Reta mediatriz_ab = ab.perpendicular((a + b) / 2.0);
        Reta mediatriz_bc = bc.perpendicular((b + c) / 2.0);

        // Se as mediatrizes forem paralelas, os pontos são colineares
        if (mediatriz_ab || mediatriz_bc) {
            o = point(HUGE_VAL, HUGE_VAL); // Ponto inválido
            r = -1.0;                      // Raio inválido
        } else {
            o = mediatriz_ab ^ mediatriz_bc;
            r = abs(o - a);
        }
    }

    // Verifica se o ponto p está dentro ou na borda do círculo
    bool contains(point p) const {
        return cmp(abs(o - p), r) <= 0;
    }

    // Calcula a área da interseção com outro círculo 'c'
    long double getIntersectionArea(const Circle& c) const {
        long double d = abs(o - c.o);
        
        // Caso 1: Círculos não se tocam ou se tocam em apenas um ponto
        if (cmp(d, r + c.r) >= 0) {
            return 0.0;
        }
        // Caso 2: Um círculo contém o outro
        if (cmp(d, abs(r - c.r)) <= 0) {
            long double min_r = min(r, c.r);
            return PI * min_r * min_r;
        }

        // Caso 3: Sobreposição parcial
        // A área é a soma das áreas de dois segmentos circulares.
        // Usamos a Lei dos Cossenos para encontrar os ângulos dos setores.
        long double angulo1 = acos((d*d + r*r - c.r*c.r) / (2*d*r));
        long double angulo2 = acos((d*d + c.r*c.r - r*r) / (2*d*c.r));

        // Área do setor - Área do triângulo = Área do segmento
        long double area_segmento1 = r*r * (angulo1 - 0.5 * sin(2*angulo1));
        long double area_segmento2 = c.r*c.r * (angulo2 - 0.5 * sin(2*angulo2));
        
        return area_segmento1 + area_segmento2;
    }
};
```
### Área de um polígono (checar se ta de acordo com o template top)
```cpp
// --- Funções para Polígonos ---

// Typedef para facilitar a leitura (já deve estar no seu template)
using polygon = vector<point>;

// Calcula a área de um polígono simples (convexo ou côncavo)
// usando a Fórmula de Shoelace. Os vértices devem estar ordenados.
// Complexidade: O(N)
double area_poligono(const polygon& poly) {
    double area_duplicada = 0.0;
    int n = poly.size();
    
    // Um polígono precisa de pelo menos 3 vértices para ter área.
    if (n < 3) return 0.0;
    
    // Itera por todos os vértices e soma os produtos vetoriais
    // de vértices adjacentes (poly[i] e poly[i+1]).
    for (int i = 0; i < n; i++) {
        area_duplicada += poly[i] % poly[(i + 1) % n];
    }
    
    // O resultado é a metade do valor absoluto da soma.
    return fabs(area_duplicada) / 2.0;
}
```
### Ângulo Entre Dois Vetores / Segmentos
```cpp
// Pré-requisito: Template Básico de Geometria 2D

// Calcula o ângulo PQR (com vértice em Q) em radianos.
double angulo(point p, point q, point r) {
    // Cria os vetores a partir do vértice Q
    point u = p - q; // Vetor QP
    point v = r - q; // Vetor QR

    // Usa os operadores sobrecarregados:
    // u % v -> produto vetorial (cross product)
    // u * v -> produto escalar (dot product)
    return atan2(u % v, u * v);
}
// para graus: double graus = angulo_radianos * 180.0 / PI;
```
### Fecho Convexo (Convex Hull) - Algoritmo de Graham Scan
O fecho convexo de um conjunto de pontos é o menor polígono convexo que contém todos os pontos. Imagine esticar um elástico em volta de todos os pontos; a forma que o elástico assume é o fecho convexo.
O algoritmo de Graham Scan resolve o problema com os seguintes passos:
Encontrar um Pivô: Escolhe-se o ponto com o menor y (e menor x como critério de desempate). Este ponto tem a garantia de fazer parte do fecho.
Ordenar por Ângulo: Os outros pontos são ordenados pelo ângulo polar que formam com o pivô, em sentido anti-horário.
Construir o Fecho: Os pontos ordenados são percorridos um a um. Usando uma estrutura de pilha, adicionamos pontos ao fecho, garantindo que a sequência de vértices sempre forme "curvas à esquerda" (sentido anti-horário). Se ao adicionar um novo ponto, a curva se torna "reta" ou "à direita", o ponto anterior é removido da pilha.
A complexidade é dominada pela ordenação, sendo **O(NlogN)**.
```cpp
// Pré-requisito: Template Básico de Geometria 2D com a struct 'point' e 'ccw'.
// A struct 'point' precisa ter o membro estático 'pivot'.

// --- Fecho Convexo (Convex Hull) ---

// Função de comparação para a Ordenação Polar em sentido anti-horário.
// Usa o 'point::pivot' global que deve ser definido antes de chamar std::sort.
bool cmp_polar(point a, point b) {
    // Usa ccw para determinar a ordem angular em relação ao pivô
    int order = ccw(point::pivot, a, b);
    if (order == 0) { // Se forem colineares com o pivô...
        // ...o ponto mais próximo do pivô vem primeiro.
        return cmp(abs(a - point::pivot), abs(b - point::pivot)) < 0;
    }
    // Caso contrário, a ordem é definida pelo sentido anti-horário.
    return order > 0;
}

// Algoritmo de Graham Scan para encontrar o Fecho Convexo.
// Modifica o vetor 'pts' para conter apenas os pontos do fecho em ordem anti-horária.
void fecho_convexo(vector<point>& pts, bool include_collinear = false) {
    if (pts.size() <= 2) {
        return;
    }

    // 1. Encontrar o pivô (ponto mais baixo e à esquerda) e colocá-lo no início.
    int pivot_idx = 0;
    for (int i = 1; i < pts.size(); i++) {
        if (cmp(pts[i].y, pts[pivot_idx].y) < 0 || 
           (cmp(pts[i].y, pts[pivot_idx].y) == 0 && cmp(pts[i].x, pts[pivot_idx].x) < 0)) {
            pivot_idx = i;
        }
    }
    swap(pts[0], pts[pivot_idx]);
    point::pivot = pts[0];

    // 2. Ordenar os pontos restantes pelo ângulo polar.
    sort(pts.begin() + 1, pts.end(), cmp_polar);
    
    // Opcional: Tratar pontos colineares no último segmento do fecho.
    // O sort já ordena os pontos colineares pela distância. Para o fecho, queremos o
    // mais distante por último, então revertemos o bloco final de pontos colineares.
    if (include_collinear) {
        int i = (int)pts.size() - 1;
        while (i > 0 && ccw(point::pivot, pts[i], pts.back()) == 0) i--;
        reverse(pts.begin() + i + 1, pts.end());
    }

    // 3. Construir o fecho.
    vector<point> hull;
    for (const auto& p : pts) {
        // Remove pontos da pilha enquanto a adição de 'p' não formar uma "curva à esquerda".
        // Uma curva à direita (ccw < 0) ou uma linha reta (ccw == 0) indica que o
        // ponto anterior se tornou interno ao novo fecho.
        while (hull.size() > 1) {
            int decision = ccw(hull[hull.size() - 2], hull.back(), p);
            if (decision < 0 || (decision == 0 && !include_collinear)) {
                hull.pop_back();
            } else {
                break;
            }
        }
        hull.push_back(p);
    }
    pts = hull;
}
```
### Par de Pontos Mais Próximo (Closest Pair of Points)
```cpp
// Pré-requisito: Template Básico de Geometria 2D com a struct 'point'.

// --- Par de Pontos Mais Próximo ---

// Função auxiliar para calcular a distância ao quadrado.
// Evitar o uso de sqrt() até o final torna o código mais rápido e preciso.
double distSq(point p1, point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

// Função de força bruta para os casos base da recursão
double closest_brute_force(const vector<point>& pts) {
    double min_dist_sq = DBL_MAX; // DBL_MAX está em <cfloat>
    for (int i = 0; i < pts.size(); ++i) {
        for (int j = i + 1; j < pts.size(); ++j) {
            min_dist_sq = min(min_dist_sq, distSq(pts[i], pts[j]));
        }
    }
    return min_dist_sq;
}

// Função recursiva principal
double closest_pair_recursive(vector<point>& pts_sorted_by_x) {
    int n = pts_sorted_by_x.size();
    
    // 1. Caso base: se há poucos pontos, usa força bruta.
    if (n <= 3) {
        return closest_brute_force(pts_sorted_by_x);
    }

    // 2. Dividir
    int mid = n / 2;
    point mid_point = pts_sorted_by_x[mid];

    // Cria os subconjuntos esquerdo e direito
    vector<point> left_half, right_half;
    for (int i = 0; i < mid; ++i) left_half.push_back(pts_sorted_by_x[i]);
    for (int i = mid; i < n; ++i) right_half.push_back(pts_sorted_by_x[i]);

    // 3. Conquistar: chama recursivamente
    double dl_sq = closest_pair_recursive(left_half);
    double dr_sq = closest_pair_recursive(right_half);
    double min_dist_sq = min(dl_sq, dr_sq);

    // 4. Combinar: verificar pares na faixa central
    vector<point> strip;
    for (const auto& p : pts_sorted_by_x) {
        // Adiciona pontos que estão na faixa de largura 2*d da linha central
        if (pow(p.x - mid_point.x, 2) < min_dist_sq) {
            strip.push_back(p);
        }
    }

    // Ordena a faixa pela coordenada Y. Este sort é o gargalo para O(N log^2 N).
    sort(strip.begin(), strip.end(), [](point a, point b){ return a.y < b.y; });

    // Verifica os pares dentro da faixa
    for (int i = 0; i < strip.size(); ++i) {
        // A otimização chave: para cada ponto, só precisamos verificar
        // um número constante de vizinhos próximos no eixo Y.
        for (int j = i + 1; j < strip.size() && pow(strip[j].y - strip[i].y, 2) < min_dist_sq; ++j) {
            min_dist_sq = min(min_dist_sq, distSq(strip[i], strip[j]));
        }
    }
    
    return min_dist_sq;
}

// Função principal que o usuário chama
double closest_pair(vector<point>& pts) {
    if (pts.size() < 2) return DBL_MAX;
    
    // Passo de pré-processamento: ordenar todos os pontos por X
    sort(pts.begin(), pts.end(), [](point a, point b){ return a.x < b.x; });
    
    // A função recursiva retorna a distância ao quadrado, então tiramos a raiz no final.
    return sqrt(closest_pair_recursive(pts));
}
```

## Strings

### String Hashing
O hashing polinomial é uma técnica poderosa para converter strings em números (hashes), permitindo comparações em tempo O(1). A complexidade para calcular os hashes de todos os prefixos de uma string de tamanho n é **O(n)**.
```cpp
// String Hashing - O(n)
// Calcula o hash de uma string inteira
long long compute_hash(const string& s) {
    const int p = 5647; // Número primo, aprox. o tamanho do alfabeto
    const int m = 1e9 + 9; // Módulo grande
    //outro modulo possivel: 1e9 + 7, outra base possivel: 4079
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
```
### Rabin-Karp (Busca de Padrão)
Utiliza hashing para encontrar todas as ocorrências de um padrão s em um texto t. A complexidade média é **O(|s| + |t|)**, mas pode degradar para **O(|s| * |t|)** em casos de muitas colisões de hash.
```cpp
// Rabin-Karp - O(|s| + |t|)
vector<int> rabin_karp(const string& s, const string& t) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.length(), T = t.length();

    // Pré-calcula potências de p
    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < p_pow.size(); i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }

    // Calcula hashes de todos os prefixos do texto 't'
    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++) {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    }

    // Calcula o hash do padrão 's'
    long long h_s = 0;
    for (int i = 0; i < S; i++) {
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        // Calcula o hash da substring atual de 't'
        long long cur_h = (h[i + S] - h[i] + m) % m;
        
        // Compara com o hash do padrão
        if (cur_h == (h_s * p_pow[i]) % m) {
            occurrences.push_back(i);
        }
    }
    return occurrences;
}
```
### Knuth-Morris-Pratt (KMP)
Um algoritmo de busca de padrão extremamente eficiente com complexidade **O(|s| + |t|)** no pior caso.
#### Função de Prefixo (LPS Array)
Primeiro, calculamos um array pi (também conhecido como LPS - Longest Proper Prefix which is also Suffix). pi[i] armazena o tamanho do maior prefixo próprio da string s[0...i] que também é um sufixo dessa mesma string.
```cpp
// KMP - Função de Prefixo - O(|s|)
vector<int> prefix_function(const string& s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
```
#### KMP (Busca de Padrão)
Com o array pi pré-calculado, o algoritmo percorre o texto e o padrão sem precisar retroceder no texto, garantindo a eficiência.
```cpp
// KMP - Algoritmo Principal - O(|t|)
vector<int> kmp(const string& t, const string& s) {
    vector<int> pi = prefix_function(s);
    vector<int> match;
    for (int i = 0, j = 0; i < t.length(); i++) {
        while (j > 0 && t[i] != s[j]) {
            j = pi[j - 1];
        }
        if (t[i] == s[j]) {
            j++;
        }
        if (j == s.length()) {
            match.push_back(i - j + 1);
            j = pi[j - 1]; // Continua a busca por mais ocorrências
        }
    }
    return match;
}
```

## Estruturas de Dados

### Sliding Window Maximum (Janela Deslizante)
```cpp
#include <bits/stdc++.h>

using namespace std;

// Sliding Window Maximum - O(n)
// Encontra o valor máximo em cada janela de tamanho 'k'.
// Retorna um vetor contendo o máximo de cada janela.
// O vetor de resultado terá `arr.size() - k + 1` elementos.

vector<int> sliding_window_max(const vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> result;
    // O deque armazena pares {valor, índice} dos elementos da janela.
    deque<pair<int, int>> dq;

    for (int i = 0; i < n; ++i) {
        // 1. Remove da frente o elemento que já saiu da janela.
        // A janela atual tem os índices [i - k + 1, i].
        if (!dq.empty() && dq.front().second <= i - k) {
            dq.pop_front();
        }

        // 2. Remove da traseira os elementos menores ou iguais ao atual,
        // pois eles nunca poderão ser o máximo enquanto o elemento atual
        // estiver na janela.
        while (!dq.empty() && dq.back().first <= arr[i]) {
            dq.pop_back();
        }

        // 3. Adiciona o elemento atual {valor, índice} na traseira.
        dq.push_back({arr[i], i});

        // 4. Se a janela já está completa, o máximo é o da frente.
        // A primeira janela completa termina no índice k-1.
        if (i >= k - 1) {
            result.push_back(dq.front().first);
        }
    }
    return result;
}
```

## Programação Dinâmica

### Problema da Mochila (Knapsack Problem)
Um problema clássico de otimização. Dado um conjunto de itens, cada um com um peso e um valor, o objetivo é determinar o número de cada item a incluir em uma coleção de modo que o peso total seja menor ou igual a uma dada capacidade (W) e o valor total seja o maior possível. A complexidade padrão das soluções com DP é O(N * W), onde N é o número de itens e W a capacidade da mochila.

1. Mochila 0/1 (0/1 Knapsack)
Nesta variação, cada item pode ser escolhido no máximo uma vez.
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001; // Máximo de itens
const int MAXW = 1001; // Capacidade máxima

int peso[MAXN], valor[MAXN];
int dp[MAXN][MAXW]; // Matriz de memoização

// Calcula o valor máximo para a Mochila 0/1
int knapsack_01_matriz(int W, int n) {
    // dp[i][w] = valor máximo usando os primeiros 'i' itens com capacidade 'w'
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // Se o item atual não cabe na mochila, a única opção é não pegá-lo.
            if (peso[i-1] > w) {
                dp[i][w] = dp[i-1][w];
            } else {
                // Se o item cabe, temos duas opções:
                // 1. Não pegar o item: o valor é o mesmo de antes (dp[i-1][w])
                // 2. Pegar o item: o valor é dp[i-1][w-peso[i-1]] + valor[i-1]
                // Escolhemos a opção que der o maior valor.
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - peso[i-1]] + valor[i-1]);
            }
        }
    }
    return dp[n][W];
}

// Reconstrói quais itens foram escolhidos a partir da matriz DP
vector<int> reconstruir_itens(int W, int n) {
    vector<int> itens_escolhidos;
    int w_atual = W;
    for (int i = n; i > 0 && w_atual > 0; --i) {
        // Compara o resultado atual com o da linha anterior.
        // Se for diferente, significa que o item 'i' foi essencial para
        // alcançar o valor em dp[i][w_atual], então ele foi escolhido.
        if (dp[i][w_atual] != dp[i-1][w_atual]) {
            itens_escolhidos.push_back(i - 1); // Adiciona o índice do item
            w_atual -= peso[i-1];
        }
    }
    return itens_escolhidos;
}
```
2. Mochila Irrestrita (Unbounded Knapsack)
Nesta variação, cada item pode ser escolhido quantas vezes quisermos. O código abaixo calcula o valor máximo e também permite reconstruir a solução (quais e quantos itens foram usados).
```cpp
#include <bits/stdc++.h>
using namespace std;

// --- Constantes e Globais ---
const int MAXN = 1001; // Máximo de itens
const int MAXW = 1001; // Capacidade máxima

int peso[MAXN], valor[MAXN];

// Vetor auxiliar para guardar qual item foi escolhido para cada capacidade.
// É preenchido pela função principal e usado pela função de reconstrução.
vector<int> item_escolhido;


// --- Funções ---

// Calcula o valor máximo para a Mochila Irrestrita e prepara a reconstrução.
int knapsack_irrestrito(int W, int n) {
    vector<int> dp(W + 1, 0);
    item_escolhido.assign(W + 1, -1);

    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (peso[i] <= w) {
                if (dp[w] < dp[w - peso[i]] + valor[i]) {
                    dp[w] = dp[w - peso[i]] + valor[i];
                    item_escolhido[w] = i; // Guarda a melhor escolha para a capacidade 'w'
                }
            }
        }
    }
    return dp[W];
}

// Reconstrói os itens usados a partir do vetor 'item_escolhido'.
// Retorna um map onde a chave é o índice do item e o valor é a quantidade.
map<int, int> reconstruir_itens_irrestrito(int W) {
    map<int, int> itens;
    int w_atual = W;

    // Volta do final, pegando a melhor escolha para cada capacidade
    while (w_atual > 0 && item_escolhido[w_atual] != -1) {
        int item_idx = item_escolhido[w_atual];
        itens[item_idx]++;
        w_atual -= peso[item_idx];
    }
    return itens;
}

/*
// --- Exemplo de como usar na main ---
int main() {
    int n, W;
    // ... ler n, W, e os vetores peso[] e valor[] ...
    
    // 1. Calcula o valor máximo e preenche o vetor 'item_escolhido'
    int max_valor = knapsack_irrestrito(W, n);
    
    // 2. Usa o vetor preenchido para descobrir os itens
    map<int, int> itens_usados = reconstruir_itens_irrestrito(W);
    
    cout << "Valor maximo: " << max_valor << endl;
    cout << "Itens usados (indice -> quantidade):" << endl;
    for (auto const& [item, qtd] : itens_usados) {
        cout << item << " -> " << qtd << endl;
    }
    return 0;
}
*/
```
### Problema do Troco (Coin Change)
Dado um conjunto de moedas de diferentes valores e uma quantia total X, o objetivo é encontrar o número mínimo de moedas necessárias para formar exatamente a quantia X.
A solução padrão usa Programação Dinâmica com a abordagem Bottom-Up (Tabulação), construindo a solução de forma iterativa. Assume-se que há uma quantidade infinita de cada tipo de moeda. A complexidade é O(N * X), onde N é o número de tipos de moeda e X é a quantia final.
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXX = 10001; // Quantia máxima
const int INF = 1e9;

// Vetor com os valores das moedas
vector<int> coins;

// Calcula o troco para 'x' de forma iterativa (Bottom-Up)
int solve_troco(int x) {
    // value[i] = o número mínimo de moedas para formar a quantia i
    vector<int> value(x + 1, INF);
    
    // Caso base: 0 moedas para formar a quantia 0
    value[0] = 0;

    // Constrói a solução para cada quantia de 1 até x
    for (int i = 1; i <= x; i++) {
        // Tenta usar cada moeda para otimizar o resultado para a quantia 'i'
        for (int c : coins) {
            if (i - c >= 0 && value[i - c] != INF) {
                // A solução para 'i' é o mínimo entre o valor atual e
                // (1 + a solução para o troco restante 'i-c')
                value[i] = min(value[i], value[i - c] + 1);
            }
        }
    }

    // Se o valor continuar INF, não é possível formar o troco.
    // Pode retornar -1 ou o próprio INF, dependendo do problema.
    return value[x] == INF ? -1 : value[x];
}

/*
// Exemplo de uso:
int main() {
    coins = {1, 3, 4};
    int x = 10;
    int resultado = solve_troco(x);
    if (resultado != -1) {
        cout << "Minimo de moedas para " << x << ": " << resultado << endl; // Saída: 3 (4+3+3)
    } else {
        cout << "Nao eh possivel formar o troco para " << x << endl;
    }
    return 0;
}
*/
```
### Caminhos em um Grid (Grid Paths)
Um problema clássico de DP para contar o número de caminhos únicos de uma célula inicial (ex: (0,0)) para uma célula final (ex: (H-1, W-1)) em um grid.
Restrições Comuns:

1. Os movimentos são restritos, geralmente apenas para baixo e para a direita.

2. Algumas células do grid podem estar bloqueadas (obstáculos).
```cpp
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
    int mat[1001][1001];
    vector<vector<int>> dp(1001, vector<int>(1001, 0));
    int h, w;
    cin >> h >> w;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char aux;
            cin >> aux;
            if(aux == '.') mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
    if(mat[0][0] == 1)dp[0][0] = 1;
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(mat[i][j] == 1){    
                if(i>0 && j>0){
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
                }
                else if(i>0){
                    dp[i][j] = dp[i-1][j] % MOD;
                }else if(j>0){
                    dp[i][j] = dp[i][j-1] % MOD;
                }
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
    return 0;
}
```   
### Problema das Atividades (Vacation Problem)
Este é um problema de DP onde o objetivo é maximizar uma pontuação ao longo de vários estágios (dias), com uma restrição sobre as escolhas em estágios consecutivos.

Descrição do Problema:
Imagine que você tem N dias de férias. Em cada dia i, você pode escolher uma de três atividades (A, B ou C), e cada uma lhe dá uma certa quantidade de "pontos de felicidade" (a[i], b[i], c[i]). A única regra é que você não pode escolher a mesma atividade em dois dias seguidos. O objetivo é escolher uma sequência de atividades que maximize a sua felicidade total.
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){

    int dp[100001][3];
    int n;
    cin >> n;
    vector<int> a, b, c;
    for(int i=0;i<n;i++){
        int auxa, auxb, auxc;
        cin >> auxa >> auxb >> auxc;
        a.push_back(auxa);
        b.push_back(auxb);
        c.push_back(auxc);
    }
    dp[0][0] = a[0]; 
    dp[0][1] = b[0]; 
    dp[0][2] = c[0]; 
    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][1] , dp[i-1][2]) + a[i]; // Para fazer a atividade 'a' hoje, ontem tivemos que fazer 'b' ou 'c'
        dp[i][1] = max(dp[i-1][0] , dp[i-1][2]) + b[i]; // Para fazer a atividade 'b' hoje, ontem tivemos que fazer 'a' ou 'c'
        dp[i][2] = max(dp[i-1][1] , dp[i-1][0]) + c[i]; // Para fazer a atividade 'c' hoje, ontem tivemos que fazer 'a' ou 'b'
    }
    cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);


    return 0;
}
```
### Maior Subsequência Crescente (LIS)
Solução Otimizada com Busca Binária - **O(NlogN)**
```cpp
// Encontra o comprimento da LIS em O(N log N)
// Solução padrão para N grande (ex: N <= 10^5)
int lis_nlogn(const vector<int>& arr) {
    if (arr.empty()) return 0;

    // 'tails' armazena a menor "cauda" (último elemento) para uma
    // subsequência crescente de um determinado comprimento.
    vector<int> tails;
    tails.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        int num = arr[i];
        
        // Se 'num' é maior que a cauda da LIS mais longa,
        // ele estende a LIS.
        if (num > tails.back()) {
            tails.push_back(num);
        } else {
            // Caso contrário, encontramos a menor cauda que é >= 'num'
            // e a substituímos por 'num'. Isso nos dá uma LIS de mesmo
            // comprimento, mas com um final menor, aumentando a chance
            // de estendê-la no futuro.
            auto it = lower_bound(tails.begin(), tails.end(), num);
            *it = num;
        }
    }

    return tails.size();
}
```
### SOS DP
**O(N*(2^N))**
```cpp
//memory optimized, super easy to code.
for(int i = 0; i<(1<<N); ++i)
	F[i] = A[i];
for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
	if(mask & (1<<i))
		F[mask] += F[mask^(1<<i)];
}
```
### Digit DP
Exemplo de digit dp,















