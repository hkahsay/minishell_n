#include"../../headers/minishell.h"

int ft_unset(char **args, t_envnode **mini_env)
{
    int i;
    //char    *res;

    i = 1;
    // (*mini_env)->content = malloc(sizeof(t_envnode) + 1);
    // (*mini_env)->content = ft_strjoin((*mini_env)->key, (*mini_env)->value);
    // printf("my content: %s\n", (*mini_env)->content);
    if (args[i] == NULL)
        return(0);
    while (args[i])
    {
        //res = check_if_in_env(*mini_env, args[i]);
        //if (res == NULL)
        //{
        printf("args[i]1 %s\n", args[i]);
        // return (0);
        remove_from_list(mini_env, args[i]);
        //}
        i++;
    }
    return (0);
}


void    remove_from_list(t_envnode **mini_env, char *key)
{
    t_envnode   *curr;
    t_envnode   *temp;
    t_envnode   *delete;
    int     len;

    curr = *mini_env;
    temp = NULL;
    len = ft_strlen(key);
    printf("len: %d\n", len);
    //if (delete_first_node(&mini_env, curr, key))
    //    return;
    //printf("min_env: %p\n", mini_env);
    while (curr && ft_strncmp(curr->key, key, len))
    {
        printf("curr->key: %s\n", curr->key);
        temp = curr;
        curr = curr->next;
        // printf("temp%s\n", temp->key);
    }

    if(temp != NULL) {
        printf("temp->key: %s\n", temp->key);
    } else {
        printf("temp is NULL\n");
    }
    printf("curr->key: %s\n", curr->key);

    // if((curr->key = NULL))
    //     return ;
    delete = curr;
    if(curr && !ft_strncmp(curr->key, key, len))
    {
        printf("Remove node\n");
        curr->next->prev = temp; // Update prev pointer
        if(temp != NULL) {
            temp->next = curr->next; // Update next pointer
        } else {
            printf("Update mini_env to previous second node\n");
            **mini_env = *curr->next;
        }
        //curr goest to next item??? can't free because it makes a segfault
        if (delete != NULL)
        {
            // free (delete->key);
            // free (delete->value);
            // delete->key = NULL;
            // delete->value = NULL;
            // free (delete);
        }
        curr = NULL;
    }
    else
        return;
}

int delete_first_node(t_envnode **head, t_envnode *curr, char *key)
{
    if (head == NULL || *head == NULL)
    {
        printf("env is empty. Cannot remove node.\n");
        return(0);
    }
    if (ft_strcmp(curr->key, key) == 0)
    {
        printf("are we here\n");
        curr = *head;
        (*head) = (*head)->next;
        printf("curr->next->key------ %s\n", curr->next->key);
        printf("head------ %s\n", (*head)->key);

        // free(curr->key);
        // free(curr->value);
        // free(curr);
        // printf("3\n");
        return(1);
    }
    return(0);   
}

char	*check_if_in_env(t_envnode *mini_env, char *arg)
{
	t_envnode	*curr;
	int		l;

	curr = mini_env;
	l = ft_strlen(arg);
	while (curr)
	{
		if (ft_strncmp(curr->key, arg, l + 1) == 0)
			return (curr->key);
		curr = curr->prev;
	}
	return (NULL);
}