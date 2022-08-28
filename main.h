enum toks { S_t, K_t, I_t, Y_t, B_t, C_t, OParen_t, CParen_t, OSquig_t, CSquig_t, OBrac_t, CBrac_t, plus_t, add1_t, sub1_t, eq_t, cond_t, true_t, false_t, err_t, int_t, var_t};
enum type { app_node, S, K, I, Y,B, C, integer, plus, add1, sub1, cond, eq, true, false, err, lam, var, prim };
char types[19][10] = {"app_node", "S",  "K", "I", "Y","B", "C", "integer", "plus", "add1", "sub1", "cond", "eq", "true", "false", "err", "lam", "var", "prim" };

//ast uses: app_node, integer, true, false, var, err, lam, var, prim
// where prim uses the values  S, K, I, Y,B, C, plus, add1, sub1, cond, eq

struct tok {
	int type;
	int value;
};

struct ast {
	int type;
	char vars[2];
	struct ast* expr1; //ALSO USED AS THE BODY FOR LAMBDAS
	struct ast* expr2;
	int value;
} ;

struct node {
	int type;
	struct node* fun;
	struct node* arg;
	int integer;
} ;

struct ast ast_plus = { prim,  {'\0','\0'}, NULL, NULL, plus};
struct ast ast_add1 = { prim,  {'\0','\0'}, NULL, NULL, add1};
struct ast ast_sub1 = { prim,  {'\0','\0'}, NULL, NULL, sub1};
struct ast ast_err = {err,  {'\0','\0'}, NULL, NULL, err};
struct ast ast_eq = {prim,  {'\0','\0'}, NULL, NULL, eq};
struct ast ast_true = {true,  {'\0','\0'}, NULL, NULL, true};
struct ast ast_false = {false,  {'\0','\0'}, NULL, NULL, false};
struct ast ast_cond = {prim,  {'\0','\0'}, NULL, NULL, cond};


struct ast ast_I = {prim,  {'\0','\0'}, NULL, NULL, I}; 
struct ast ast_K = {prim,  {'\0','\0'}, NULL, NULL, K};
struct ast ast_S = {prim,  {'\0','\0'}, NULL, NULL, S};
struct ast ast_B = {prim,  {'\0','\0'}, NULL, NULL, B};
struct ast ast_C = {prim,  {'\0','\0'}, NULL, NULL, C};
struct ast ast_Y = {prim,  {'\0','\0'}, NULL, NULL, Y};


//universal nodes for the final tree
struct node node_plus = { plus, NULL, NULL, 0};
struct node node_add1 = { add1, NULL, NULL, 0};
struct node node_sub1 = { sub1, NULL, NULL, 0};
struct node node_err = {err, NULL, NULL, 0};
struct node node_eq = {eq, NULL, NULL, 0};
struct node node_true = {true, NULL, NULL, 0};
struct node node_false = {false, NULL, NULL, 0};
struct node node_cond = {cond, NULL, NULL, 0};

struct node node_I = {I, NULL, NULL, 0}; 
struct node node_K = {K, NULL, NULL, 0};
struct node node_S = {S, NULL, NULL, 0};
struct node node_B = {B, NULL, NULL, 0};
struct node node_C = {C, NULL, NULL, 0};
struct node node_Y = {Y, NULL, NULL, 0};

int tokenize(char* string, struct tok* tok_list);
void print_token(struct tok* token_print);
void print_tokens(struct tok* token_print, int length);
void ast_copy(struct ast* dest, struct ast* src, int amount) ;
void print_tree(struct node* head_node, int level);
void print_ast(struct ast* head_node, int level) ;
int parse(struct tok* tokens, int length, struct ast* head_ast);
int check_null(struct node* head_node, int check);

int reduce_node(struct node* head_node, struct node* next_alloc);
int check_optimization(int type, struct ast* fun, struct ast* arg) ;
int bracket_abstract(struct ast* asts, char variable, struct ast* new_alloc ) ;
int create_tree(struct ast* asts, struct node* nodes) ;

