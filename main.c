#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "main.h"

//tokenizes a character strings - put the results in the tok_list
int tokenize(char* string, struct tok* tok_list) {
	
	FILE *file;
	file = fopen("prog.txt", "r");
	size_t n = 0;
	int c;
	
	
	if (file == NULL) {
		printf("File not Found \n");
		return 1;
	}
	
	while ((c = fgetc(file)) != EOF){
		string[n++] = (char) c;
	}
	
	string[n] = '\0';
	
	
	
	int i = 0;
	int i_tok = 0;
	
	char* plus_word = "plus";
	char* add1_word = "add1";
	char* sub1_word = "sub1";
	char* err_word = "err";
	char* cond_word = "cond";
	char* eq_word = "eq";
	char* true_word = "true";
	char* false_word = "false";
	char* def = "def";
	
	while (i < 500 && string[i] != '\0'){
		if (string[i] == ' ' || string[i] == '\n' || string[i] == 13) {
			i += 1;
		} else {
			if (string[i] == 'S'){
				struct tok s_tok = { S_t, 0};
				tok_list[i_tok++] = s_tok;
				i += 1;
			} else if (string[i] == 'K'){
				struct tok K_tok = {K_t, 0};
				tok_list[i_tok++] = K_tok;
				i += 1;
			} else if (string[i] == 'I'){
				struct tok I_tok ={ I_t, 0} ;
				tok_list[i_tok++] = I_tok;
				i += 1;
			} else if (string[i] == 'Y'){
				struct tok Y_tok ={ Y_t, 0} ;
				tok_list[i_tok++] = Y_tok;
				i += 1;
			} else if (string[i] == 'B'){
				struct tok B_tok ={ B_t, 0} ;
				tok_list[i_tok++] = B_tok;
				i += 1;
			} else if (string[i] == 'C'){
				struct tok C_tok ={ C_t, 0} ;
				tok_list[i_tok++] = C_tok;
				i += 1;
			} else if (string[i] == '('){
				struct tok OParen_tok = { OParen_t, 0};
				tok_list[i_tok++] = OParen_tok;
				i += 1;
			} else if (string[i] == ')'){
				struct tok CParen_tok = { CParen_t, 0};
				tok_list[i_tok++] = CParen_tok;
				i += 1;
			} else if (string[i] == ')'){
				struct tok CParen_tok = { CParen_t, 0};
				tok_list[i_tok++] = CParen_tok;
				i += 1;
			} else if (string[i] == '{'){
				struct tok OSquig_tok = { OSquig_t, 0};
				tok_list[i_tok++] = OSquig_tok;
				i += 1;
			} else if (string[i] == '}'){
				struct tok CSquig_tok = { CSquig_t, 0};
				tok_list[i_tok++] = CSquig_tok;
				i += 1;
			} else if (string[i] == '['){
				struct tok OBrac_tok = { OBrac_t, 0};
				tok_list[i_tok++] = OBrac_tok;
				i += 1;
			} else if (string[i] == ']'){
				struct tok CBrac_tok = { CBrac_t, 0};
				tok_list[i_tok++] = CBrac_tok;
				i += 1;
			}  else if (strstr(&string[i], plus_word) == &(string[i]) ){
				struct tok Plus_tok = { plus_t, 0}; 
				tok_list[i_tok++] = Plus_tok;
				i += 4;
			} else if (strstr(&string[i], add1_word) == &(string[i]) ){
				struct tok Add1_tok = { add1_t, 0}; 
				tok_list[i_tok++] = Add1_tok;
				i += 4;
			} else if (strstr(&string[i], sub1_word) == &(string[i]) ){
				struct tok Sub1_tok = { sub1_t, 0}; 
				tok_list[i_tok++] = Sub1_tok;
				i += 4;
			} else if (strstr(&string[i], err_word) == &(string[i]) ){
				struct tok Err_tok = { err_t, 0}; 
				tok_list[i_tok++] = Err_tok;
				i += 3;
			}  else if (strstr(&string[i], eq_word) == &(string[i]) ){
				struct tok Eq_tok = { eq_t, 0}; 
				tok_list[i_tok++] = Eq_tok;
				i += 2;
			} else if (strstr(&string[i], cond_word) == &(string[i]) ){
				struct tok Cond_tok = { cond_t, 0}; 
				tok_list[i_tok++] = Cond_tok;
				i += 4;
			} else if (strstr(&string[i], true_word) == &(string[i]) ){
				struct tok True_tok = { true_t, 0}; 
				tok_list[i_tok++] = True_tok;
				i += 4;
			}  else if (strstr(&string[i], false_word) == &(string[i]) ){
				struct tok False_tok = { false_t, 0}; 
				tok_list[i_tok++] = False_tok;
				i += 5;
			} else if (string[i] <= 0x39 && string[i] >= 0x30 ) {
		
				int place = 0;
				int value = 0;
				while (string[i] <= 0x39 && string[i] >= 0x30 ){
					value = value * 10;
					value += (string[i] - 0x30);
					i += 1;
				}
				struct tok int_tok = {int_t, value}; 
				tok_list[i_tok++] = int_tok;
				

			} else {
				
				int value = string[i];
				struct tok var_tok = {var_t, value}; 
				tok_list[i_tok++] = var_tok;
				i += 1;
				
			}
						
		}	
	}
	return i_tok;

}

//printing functions for debugging
void print_token(struct tok* token_print){
	//printf("type: %d value: %d\n", token_print->type, token_print->value);
	switch (token_print->type) {
		case S_t:
			printf("S ");
			break;
		case K_t:
			printf("K ");
			break;
		case I_t:
			printf("I ");
			break;
		case Y_t:
			printf("Y ");
			break;
		case B_t:
			printf("B ");
			break;
		case C_t:
			printf("C ");
			break;
		case OParen_t:
			printf("( ");
			break;
		case CParen_t:
			printf(") ");
			break;
		case OSquig_t:
			printf("{ ");
			break;
		case CSquig_t:
			printf("} ");
			break;
		case plus_t:
			printf("plus ");
			break;
		case CBrac_t:
			printf("] ");
			break;
		case OBrac_t:
			printf("[ ");
			break;
		case add1_t:
			printf("add1 ");
			break;
		case sub1_t:
			printf("sub1 ");
			break;
		case eq_t:
			printf("eq ");
			break;
		case cond_t:
			printf("cond ");
			break;
		case int_t:
			printf("%d ", token_print->value);
			break;
		case var_t:
			printf("%c ", (char)token_print->value);
			break;
		default:
			printf("type: %d value: %d\n", token_print->type, token_print->value);
			break;
	}
}
void print_tokens(struct tok* token_print, int length){
	int i;
	for (i = 0; i < length; i ++){
		print_token( &token_print[i] );
	}
	printf("\n");
	fflush(stdout);
}
void print_tree(struct node* head_node, int level) {
	
	if (head_node->type == app_node) {
		int i = 0;
		
		
		for(i = 0; i < level; i ++ ){
		 printf(" ");
		}
		
		
		printf("app_node\n");
		fflush(stdout);
		i = 0;
		
		
		for(i = 0; i < level; i ++ ){
		 printf(" ");
		}
		
		printf("fun:");
		if (head_node->fun != NULL){
			print_tree(head_node->fun, level + 1);
		}
		i = 0;
		
		
		for(i = 0; i < level; i ++ ){
		 printf(" ");
		}
		printf("arg:");
		fflush(stdout);
		
		if (head_node->arg != NULL){
			print_tree(head_node->arg, level + 1);
		} 
		
		
	} else {
		int i;
		for(i = 0; i < level; i ++ ){
		 printf(" ");
		}
		
		printf("type: %s", types[head_node->type]);
		printf("\n");
	}
	
	
	fflush(stdout);
	
	
}
void print_ast(struct ast* head_node, int level) {
	
	if (head_node->type == app_node) {
		int i = 0;
		
		
		for(i = 0; i < level; i ++ ){
		 printf(" ");
		}
		
		
		printf("app_node\n");
		fflush(stdout);
		i = 0;
		
		
		for(i = 0; i < level; i ++ ){
		 printf(" ");
		}
		
		printf("fun:");
		if (head_node->expr1 != NULL){
			print_ast(head_node->expr1, level + 1);
		}
		i = 0;
		
		
		for(i = 0; i < level; i ++ ){
		 printf(" ");
		}
		printf("arg:");
		fflush(stdout);
		
		if (head_node->expr2 != NULL){
			print_ast(head_node->expr2, level + 1);
		} 
		fflush(stdout);
		
	} else {
		int i;
		for(i = 0; i < level; i ++ ){
		 printf(" ");
		}
		
		printf("type: %s", types[head_node->type]);
		
		if (head_node->type == prim) {
			printf(" %s ", types[head_node->value] );
			
		} else if (head_node->type == lam) {
			printf( " %s ", (head_node->vars) );
		}
		else if (head_node->type == var) {
			printf( " %c ", (char)(head_node->value) );
		}
		
		printf("\n");
		
		fflush(stdout);
	}
	
	
}

//makes the initial AST
int parse(struct tok* tokens, int length, struct ast* head_ast) {
	//print_tokens(tokens, length);
	
	if (length == 0)  {
		return 0;
	}
	
	int last_type = tokens[length - 1].type;
	
	if ( last_type == CParen_t) {
		//printf("cparen token:");
		//fflush(stdout);
		//the argument is in ()
		int start_idx = length - 2;
		int num_close_paren = 1;
		int num_start_paren = 0;
		
		while (start_idx > -1 && num_start_paren < num_close_paren) {
			if (tokens[start_idx].type == OParen_t) {
				num_start_paren += 1;
			} else if (tokens[start_idx].type == CParen_t) {
				num_close_paren += 1;
			}
			start_idx -= 1;
		
		}
		
		if (num_start_paren != num_close_paren) {
			head_ast = NULL;
			return 0;
		}

		if (start_idx == -1) {
			return parse( &tokens[1], length - 2, head_ast);
		} else {
			start_idx += 2;
			
			head_ast->type = app_node;
			
			
			
			
			struct ast* fun_ast = &(head_ast[1]);
			int fun_len = parse( tokens, start_idx - 1, fun_ast);
			head_ast->expr1 = fun_ast;
			
			struct ast* arg_ast = &(head_ast[1 + fun_len]);
			int arg_len = parse( &tokens[start_idx], length - 1 - start_idx, arg_ast);
			head_ast->expr2 = arg_ast;
			
			head_ast->value = 0;
			
			return 1 + fun_len + arg_len;
		}
			
	} else if (last_type == CSquig_t) {
		// have something that needs bracket abstraction
		int start_idx = length - 2;
		int num_close_paren = 1;
		int num_start_paren = 0;
		
		while (start_idx >= 0 && num_start_paren < num_close_paren) {
			if (tokens[start_idx].type == OSquig_t) {
				num_start_paren += 1;
			} else if (tokens[start_idx].type == CSquig_t) {
				num_close_paren += 1;
			}
			start_idx -= 1;
		
		}
		
		if (num_start_paren != num_close_paren) {
			head_ast = NULL;
			return 0;
		}
		
		
		//printf("start %d end %d\n", start_idx, length - 1);
		//fflush(stdout);
		
		start_idx += 2;
		
		//get the list of variables that need to be abstracted out
		char vars[2] = "\0\0";
		
		assert( tokens[start_idx].type == OBrac_t );
		
		int var_idx = start_idx + 1;
		int var_arr_idx = 0;
		while ( tokens[var_idx].type == var_t ) {
			vars[var_arr_idx] = (char)tokens[var_idx].value;
			var_arr_idx ++;
			var_idx ++;
		}

		
		var_arr_idx --; //gets the index of the last variable in vars
		
		assert( tokens[var_idx].type == CBrac_t );
		var_idx ++; // make it so that var_idx is the start of the body
		// then length - 1 is the end of the body.
				
		
		struct ast new_ast = {lam, {vars[0], vars[1]}, NULL, NULL, 0};


		if (start_idx == 1) {
			//it's a function, just parse and return
			
			int parsed_len = parse( &tokens[var_idx], length - 1 - var_idx, &(head_ast[1]) );
			new_ast.expr1 = &(head_ast[1]);
			head_ast[0] = new_ast;
			return 1 + parsed_len;
			
		} else {
			head_ast->type = app_node;


			struct ast* fun_ast = &(head_ast[1]);
			int fun_len = parse( tokens, start_idx - 1, fun_ast);
			head_ast->expr1 = fun_ast;
			
			int arg_len = parse( &tokens[var_idx], length - 1 - var_idx, &(head_ast[2 + fun_len]) );
			new_ast.expr1 = &(head_ast[2 + fun_len]);
			head_ast[1 + fun_len] = new_ast;	
			head_ast->expr2 = &(head_ast[1 + fun_len]);
			
			return 2 + fun_len + arg_len;
			
			
		}
		
		
	} else if (last_type == int_t || last_type == var_t) {
		//printf("int token:\n");
		//fflush(stdout);
		
		//have to create a new node anyway
		//struct node* arg_node = (struct node*)malloc(sizeof(struct node));
		struct ast new_ast = {integer, {'\0','\0'}, NULL, NULL, tokens[length-1].value};
		
		if (last_type == var_t) {
			new_ast.type = var;
			new_ast.value = (char)tokens[length-1].value;
		}

		if (length == 1) {
			head_ast[0] = new_ast;
			return 1;
		} else  {
			head_ast->type = app_node;
		
			
			struct ast* fun_ast = &(head_ast[1]);
			int fun_len = parse( tokens, length - 1, fun_ast);
			head_ast->expr1 = fun_ast;
			
			head_ast[1 + fun_len] = new_ast;
			head_ast->expr2 = &(head_ast[1 + fun_len]);

			return 2 + fun_len;
		}
	} else {
		struct ast chosen_ast;

		if (last_type == S_t){
			chosen_ast = ast_S;
		} else if (last_type == K_t){
			chosen_ast = ast_K;
		} else if (last_type == I_t){
			chosen_ast = ast_I;
		}  else if (last_type == Y_t){
			chosen_ast = ast_Y;
		} else if (last_type == B_t){
			chosen_ast = ast_B;
		} else if (last_type == C_t){
			chosen_ast = ast_C;
		} else if (last_type == plus_t){
			chosen_ast = ast_plus;
		} else if (last_type == add1_t){
			chosen_ast = ast_add1;
		} else if (last_type == sub1_t){
			chosen_ast = ast_sub1;
		} else if (last_type == cond_t){
			chosen_ast = ast_cond;
		}  else if (last_type == eq_t){
			chosen_ast = ast_eq;
		} else if (last_type == true_t){
			chosen_ast = ast_true;
		}  else if (last_type == false_t){
			chosen_ast = ast_false;
		} else if (last_type == err_t){
			chosen_ast = ast_err;
		}  
	
		if (length == 1) {
			head_ast[0] = chosen_ast;
			return 1;
		} else {
			head_ast->type = app_node;
		
			struct ast* fun_ast = &(head_ast[1]);
			int fun_len = parse( tokens, length - 1, fun_ast);			
			head_ast->expr1 = fun_ast;
			
			head_ast[1 + fun_len] = chosen_ast;
			
			head_ast->expr2 = &(head_ast[1 + fun_len]);
			
			return 2 + fun_len;
		
		}
		
			
		
	}
			


}

//checks to see if the B, C, and other bracket abstraction optimizations are possible
int check_optimization(int type, struct ast* fun, struct ast* arg) {
	if (type == 0) {
		//check for S (K E1) (K E2) -> K (E1 E2)
		if (fun == NULL || arg == NULL || fun->expr1 == NULL || arg->expr1 == NULL || fun->expr2 == NULL || arg->expr2 == NULL) {
			return 0;
		}
		if (fun->expr1->type == prim && fun->expr1->value == K && arg->expr1->type == prim && arg->expr1->value == K) {
			return 1;
		}
	} else if (type == 1) {
		//check for S (K E1) I -> E1
		if (fun == NULL || arg == NULL || fun->expr1 == NULL || fun->expr2 == NULL) {
			return 0;
		}
		if (fun->expr1->type == prim && fun->expr1->value == K && arg->type == prim && arg->value == I ) {
			return 1;
		}
	} else if (type == 2) {
		//check for S (K E1) E2 
		if (fun == NULL || arg == NULL || fun->expr1 == NULL || fun->expr2 == NULL) {
			return 0;
		}
		if (fun->expr1->type == prim && fun->expr1->value == K ) {
			return 1;
		}
	} else if (type == 3) {
		//check for S (K E1) E2 
		if (fun == NULL || arg == NULL || arg->expr1 == NULL || arg->expr2 == NULL) {
			return 0;
		}
		if (arg->expr1->type == prim && arg->expr1->value == K ) {
			return 1;
		}
	}
	
	return 0;
}

//copies an ast from one memory location to another
void ast_copy(struct ast* dest, struct ast* src, int amount) {
	int i;
	for (i = 0; i < amount; i ++ ) {
		dest[i] = src[i];
	}
}

//processes a lambda function - will call bracket_abstract on all the variables in the lambda
int process_lambda( struct ast* asts, struct ast* local_ast) {
	struct ast head_ast = asts[0];
	if (local_ast == NULL) {
		asts = NULL;
		return 0;
	}
	//copy into the local_ast the head_ast body
	ast_copy(local_ast, head_ast.expr1, 500);

	int i;
	//destination: the pointer, char, bodys
	int brac_len = 500;
	for (i = 1; i >= 0; i -- ) {
		if (head_ast.vars[i] != '\0') {
			int old_brac_len = brac_len;
			brac_len += bracket_abstract( local_ast , head_ast.vars[i], &(local_ast[brac_len]) );
			//printf("abstracted out %c\n", head_ast.vars[i]);
			//print_ast(local_ast, 0);
			
		}
	}	
	return brac_len;

}

//does the bracket abstraction
int bracket_abstract(struct ast* asts, char variable, struct ast* new_alloc ) {

	if (asts == NULL) {
		return 0;
	}

	if (asts[0].type == app_node) {

		//bracket abstract from both sides
		struct ast* fun_ast = &(new_alloc[2]);

		int fun_len = bracket_abstract( asts[0].expr1, variable, fun_ast);

		struct ast* arg_ast = &(new_alloc[3 + fun_len]);
		int arg_len = bracket_abstract( asts[0].expr2, variable, arg_ast);

		
		if (fun_ast == NULL || arg_ast == NULL ) {
			asts = NULL;
			return 0;
		}
		
		//will be an S, check for optimizations
		
		struct ast* newfun = asts[0].expr1;
		struct ast* newarg = asts[0].expr2;
		    
		if ( check_optimization(0, newfun, newarg) ) {

			//S (K E1) (K E2) -> K (E1 E2)
			struct ast sub_ast = {app_node, {'\0','\0'}, newfun->expr2, newarg->expr2, 0};
			*(new_alloc) = sub_ast;	
			struct ast head_ast = {app_node, {'\0','\0'}, &ast_K, &(new_alloc[0]), 0} ;
			*(asts) = head_ast;
			
		} else if (  check_optimization(1, newfun, newarg)){
			//S (K E1) I -> E1
			*(asts) = *(newfun->expr2);
		} else if (	 check_optimization(2, newfun, newarg)) {
			//check for S (K E1) E2 -> B E1 E2
			struct ast orig_B = {prim,  {'\0','\0'}, NULL, NULL, B};
			new_alloc[1] = orig_B;
			struct ast sub_ast = {app_node, {'\0','\0'}, &(new_alloc[1]), newfun->expr2};
			*(new_alloc) = sub_ast;	
			struct ast head_ast = {app_node, {'\0','\0'},  &(new_alloc[0]), newarg, 0} ;
			*(asts) = head_ast;
		} else if ( check_optimization(3, newfun, newarg)) {
		
			//check for S E1 (K E2) -> C E1 E2
			struct ast orig_C = {prim,  {'\0','\0'}, NULL, NULL, C};
			new_alloc[1] = orig_C;
			struct ast sub_ast = {app_node, {'\0','\0'}, &(new_alloc[1]), newfun};
			*(new_alloc) = sub_ast;	
			struct ast head_ast = {app_node, {'\0','\0'},  &(new_alloc[0]), newarg->expr2, 0} ;
			*(asts) = head_ast;
		} else {
			struct ast orig_S = {prim,  {'\0','\0'}, NULL, NULL, S};
			new_alloc[1] = orig_S;
			struct ast sub_ast = {app_node, {'\0','\0'}, &(new_alloc[1]), newfun, 0};
			*(new_alloc) = sub_ast;	
			struct ast head_ast = { app_node, {'\0','\0'}, new_alloc, newarg, 0 };
			*(asts) = head_ast;
		}
		

		return 4+ fun_len + arg_len;
		
	} else if (asts[0].type == var && (char)asts[0].value == (char)variable) {
		asts[0] = ast_I;
		return 0;
	} else if (asts[0].type == lam) {

		//the new ast will be at the start of new_alloc
		int brac_len = process_lambda(asts, new_alloc);
		//now have an ast that we can bracket abstract our variable from
		int new_brac_len = bracket_abstract(new_alloc,  variable, &(new_alloc[brac_len]) );
		
		//copy to head node
		*(asts) = *(new_alloc);
		
		return brac_len + new_brac_len;
		
	} else if (asts[0].type != app_node) {
		
		struct ast copy_ast;
		copy_ast.type = asts[0].type;
		copy_ast.expr1 = NULL;
		copy_ast.expr2 = NULL;
		copy_ast.value = asts[0].value;
		*(new_alloc) = copy_ast;

		struct ast orig_K = {prim,  {'\0','\0'}, NULL, NULL, K};
		new_alloc[1] = orig_K;
		
		struct ast head_ast = {app_node, {'\0','\0'},  &(new_alloc[1]), new_alloc, 0 };
		*(asts) = head_ast;
		
		return 2;
	}
	return 0;
}

//creates the tree from an AST graph
int create_tree(struct ast* asts, struct node* nodes) {
	struct ast head_ast = asts[0];
	int head_type = head_ast.type;
	
	if (head_type == app_node) {
		struct node* fun_node = &(nodes[1]);
		int fun_len = create_tree( head_ast.expr1, fun_node);

		struct node* arg_node = &(nodes[1 + fun_len]);
		int arg_len = create_tree( head_ast.expr2, arg_node);
		
		struct node head_node = {app_node, fun_node, arg_node, 0};	
		nodes[0] = head_node;
		
		
		return 1 + fun_len + arg_len;
	} else if (head_type == prim || head_type == true || head_type == false || head_type == err) {
		
		struct node prim_node = {plus, NULL, NULL, 0};
		//create a prim node and move on
		
		//printf("%s\n", types[head_ast.value] );
		//fflush(stdout);
		
		prim_node.type = head_ast.value;
		nodes[0] = prim_node;
		return 1;
	} else if (head_type == integer) {
		
		struct node int_node = {integer, NULL, NULL, head_ast.value};
		nodes[0] = int_node;
		return 1;
	} else if (head_type == lam) {
		//do bracket abstraction
		struct ast* local_ast = (struct ast*)malloc(2500 * sizeof(struct ast)); //destination
		
		
		int brac_len = process_lambda(asts, local_ast);
		
		//cop
		//create tree from that
		int length = create_tree( local_ast, nodes);
		free(local_ast);
		return length;
		
		
		
	}
	nodes = NULL;
	return 0;
}

//checks to see if various reductions can be done
int check_null(struct node* head_node, int check){
    if (check == S || check == cond || check == B || check == C) {
        if (head_node->fun->fun == NULL || head_node->fun->arg == NULL) {
            return 0;
        } else if (head_node->fun->fun->fun == NULL || head_node->fun->fun->arg == NULL){
            return 0;
        }
    } else if (check == K){
        if (head_node->fun->fun == NULL || head_node->fun->arg == NULL){
            return 0;
        }
            
    
    } else if (check == plus || check == eq){
        if (head_node->fun->arg == NULL){
            return 0;
        }
    } 
    
    return 1;
}

//does the actual graph reduction
int reduce_node(struct node* head_node, struct node* next_alloc){
	
	// something has to be an application node in order to be reduced
	if (head_node == NULL || head_node->type != app_node){
		return 0;
	//has to be an application node, meaning that it should have a vald fun and arg
	//if not, then it's probably like some terminal, meaning that you can just return
	} else if (head_node->fun == NULL || head_node->arg == NULL){
	    return 0;
	}
	
	if (check_null(head_node, S) && (head_node->fun->fun->fun->type == S)) {
		struct node* f = head_node->fun->fun->arg;
		struct node* g = head_node->fun->arg;	
		struct node* x = head_node->arg;
		
		struct node* fx = &(next_alloc[0]);
		struct node fun_node = {app_node, f, x, 0};
		*fx = fun_node;
		int fun_len = reduce_node(fx, &(next_alloc[1]) );
				
		struct node* gx = &(next_alloc[1 + fun_len]);
		struct node arg_node = {app_node, g, x, 0};
		*gx = arg_node;
		//reduce_node(gx); -> doing this would cause it to not be lazy anymore

		struct node node_together = {app_node, fx, gx, 0};
		*head_node = node_together;
		return 2 + fun_len;
		
		
	} else if (check_null(head_node, B) && (head_node->fun->fun->fun->type == B) ) {
		struct node* f = head_node->fun->fun->arg;
		struct node* g = head_node->fun->arg;	
		struct node* x = head_node->arg;
		
		int fun_len = reduce_node(f, &(next_alloc[0]) );
		
		struct node* gx = &(next_alloc[1 + fun_len]);
		struct node arg_node = {app_node, g, x, 0};
		*gx = arg_node;
		
		struct node node_together = {app_node, f, gx, 0};
		*head_node = node_together;
		
		return 2 + fun_len;
		
	} else if (check_null(head_node, C) && (head_node->fun->fun->fun->type == C) ) {
		struct node* f = head_node->fun->fun->arg;
		struct node* g = head_node->fun->arg;	
		struct node* x = head_node->arg;
		
		struct node* fx = &(next_alloc[0]);
		struct node fun_node = {app_node, f, x, 0};
		*fx = fun_node;
		int fun_len = reduce_node(fx, &(next_alloc[1]));

		struct node node_together = {app_node, fx, g, 0};
		*head_node = node_together;
		
		return 1 + fun_len;
		
	} else if (check_null(head_node, K) && head_node->fun->fun->type == K ){
		
		*head_node = *(head_node->fun->arg);
		return 0;
	} else if (head_node->fun->type == I){
		*head_node = *(head_node->arg);
		return 0;
	
	} else if (check_null(head_node, plus) && head_node->fun->fun->type == plus){
		struct node* arg1 = head_node->fun->arg;
		
		int arg1_len = 0;
		int arg2_len = 0;
		
		while(arg1->type == app_node){
			arg1_len += reduce_node(arg1, &(next_alloc[arg1_len]) );
		}
		
		if (arg1->type != integer) {
			*head_node = node_err;
			return 0;
		}
		
		struct node* arg2 = head_node->arg;
		
		while(arg2->type == app_node){
			arg2_len += reduce_node(arg2, &(next_alloc[arg1_len + arg2_len]));	
		}
		
		if (arg2->type != integer) {
			*head_node = node_err;
			return 0;
		}
		
		struct node int_node = {integer, NULL, NULL, head_node->fun->arg->integer + head_node->arg->integer};
		*head_node = int_node;
		return arg1_len + arg2_len;
	
	} else if (head_node->fun->type == add1 || head_node->fun->type == sub1) {
		//reduce the argument to an integer
		int arg_len = 0;
		
		
		while(head_node->arg->type == app_node){
			arg_len += reduce_node(head_node->arg, &(next_alloc[arg_len]) );
		}
		
		if (head_node->arg->type != integer) {
			*head_node = node_err;
			return 0;
		}
		struct node int_node = {integer, NULL, NULL, head_node->arg->integer - 1};
		if (head_node->fun->type == add1) {
			int_node.integer = 1 + head_node->arg->integer;
		} 
		*head_node = int_node;
		return arg_len;
		
	} else if (check_null(head_node, eq) && head_node->fun->fun->type == eq){
		int arg1_len = 0;
		int arg2_len = 0;
		
		struct node* arg1 = head_node->fun->arg;

		while(arg1->type == app_node){
			arg1_len += reduce_node(arg1, &(next_alloc[arg1_len]) );
		}
		
		if (arg1->type == err) {
			*head_node = node_err;
			return arg1_len;
		}
		
		struct node* arg2 = head_node->arg;
		
		while(arg2->type == app_node){
			arg2_len += reduce_node(arg2, &(next_alloc[arg1_len + arg2_len]));	
		}
		
		if (arg2->type == err) {
			*head_node = node_err;
			return arg1_len + arg2_len;
		}
		//check field equality
		if (arg1->type == true && arg2->type == true) {
			*head_node = node_true;
		} else if (arg1->type == false && arg2->type == false) {
			*head_node = node_true;
		} else if (arg1->type == integer && arg2->type == integer && arg1->integer == arg2->integer) {
			*head_node = node_true;
		} else {
			*head_node = node_false;
		}
		return arg1_len + arg2_len;
	
	} else if (check_null(head_node, cond) && head_node->fun->fun->fun->type == cond ) {
		struct node* conditional = head_node->fun->fun->arg;
		
		int arg_len = 0;
		
		while(conditional->type == app_node){
			arg_len += reduce_node(conditional, &(next_alloc[arg_len]) );
		}
		
		if (conditional->type == err) {
			*head_node = node_err;
		} else if (conditional->type == true) {
			*head_node = *(head_node->fun->arg);
		} else if (conditional->type == false) {
			*head_node = *(head_node->arg);
		} else {
			*head_node = node_err;
		}
		
		return arg_len;
	} else {
		//generic app node, reduce the left side
		return reduce_node(head_node->fun, next_alloc);
	}
	
	//return head_node;
}


int main () {
	
	char* text = malloc(500 * sizeof(char));
	struct tok* toks = malloc(500 * sizeof(struct tok) );
	struct ast* asts = malloc(2500 * sizeof(struct ast) );
	struct node* nodes = malloc(1500 * sizeof(struct ast) );
	
	if (text == NULL || toks == NULL || asts == NULL || nodes == NULL ){
		printf("Not enough memory");
		return 1;
	}
	
	int num_toks = tokenize( text, toks);
	//print_tokens(toks, num_toks);
	
	if (num_toks == -1) {
		printf("invalid token spotted\n");
		free(text);
		free(toks);
		free(asts);
		free(nodes);
		return 1;
	}
		
	int ast_len = parse(toks, num_toks, asts);
	//print_ast(asts, 0);
	
	int tree_len = create_tree(asts, nodes);
	//print_tree(nodes, 0);
	
	while(nodes[0].type == app_node && nodes[0].type != err){
	    tree_len += reduce_node( nodes, &(nodes[tree_len]) );
	}
	
	struct node test_node = nodes[0];
	
	
	if (test_node.type == err) {
		printf("err occurred\n");
	} else if (test_node.type == true) {
		printf("true\n");
	} else if (test_node.type == false) {
		printf("false\n");
	} else if (test_node.type == integer) {
		printf("%d\n", test_node.integer);
	}
	
	
	free(text);
	free(toks);
	free(asts);
	free(nodes);


	
	return 0;
}