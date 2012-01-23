struct dictionary *dict_new(unsigned int size, unsigned int universe){
	struct dictionary *t;
	t = (struct dictionary *)malloc(sizeof(struct dictionary));
	t->size = 0;
	return t;
}

int dict_empty(struct dictionary *d){
	return d->size == 0;
}

void dict_set(struct dictionary *d, unsigned int key, unsigned int value){
	if(dict_empty(d)){
		struct node *new;
		new = (struct node *)malloc(sizeof(struct node));		
		new->key = key;
		new->value = value;
		d->root = new;
	}
	else
		insert(d->root,key,value);
	d->size++;
}

int dict_get(struct dictionary *d, unsigned int key){
	return get(d->root,key);
}

void dict_delete(struct dictionary *d, unsigned int key){
	if(delete(&(d->root),key) != NULL)
		d->size--;
}

void dict_free(struct dictionary *d){
	node_free(d->root);
	free(d);
}

struct node *insert(struct node *r, unsigned int key, unsigned int value){
	if(r == NULL){
		struct node *new;
		new = (struct node *)malloc(sizeof(struct node));
		new->key = key;
		new->value = value;
		r = new;
		return r;
	}
	if(r->key == key);
	if(key < r->key)
		r->left = insert(r->left,key,value);
	else
		r->right = insert(r->right,key,value);
	return r;
}

int get(struct node *r, unsigned int key){
	if(r == NULL)
		return -1;
	if(r->key == key)
		return r->value;
	if(key < r->key)
		return get(r->left,key);
	if(key > r->key)
		return get(r->right,key);
	else
		return -1;
}

struct node *delete(struct node **r, unsigned int key){
	struct node *t;
	struct node *aux;
	t = *r;
	if(t == NULL)
		return NULL;
	if(key < t->key)
		t->left = delete(&(t->left),key);
	else if(key > t->key)
		t->right = delete(&(t->right),key);
	else{
		if(t->left != NULL && t->right != NULL){
			aux = find_min(t->right);
			t->key = aux->key;
			t->value = aux->value;
			t->right = delete(&(t->right),t->key);
		}
		else{
			aux = *r;
			if((*r)->left == NULL)
				*r = (*r)->right;
			else if((*r)->right == NULL)
				*r = (*r)->left;
			free(aux);
		}
	}
	return *r;
}

struct node *find_min(struct node *r){
	if(r == NULL)
		return NULL;
	else
		if(r->left == NULL)
			return r;
		else
			return find_min(r->left);
}


void node_free(struct node *r){
	if(r == NULL) return;
	node_free(r->left);
	node_free(r->right);
	memset(r,0,sizeof(struct node));
	free(r);
}

void tree_print(struct node *r, int floor){
	int i;
	for(i = 0; i < floor;i++)
		printf("\t");
	if(r == NULL)
		printf("null\n");
	else{
		printf("key: %d value: %d\n",r->key,r->value);
		tree_print(r->left,floor+1);
		tree_print(r->right,floor+1);
	}
}
