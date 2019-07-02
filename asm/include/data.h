/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** data
*/

#ifndef DATA_H_
#define DATA_H_

#define LIVE (op_tab[0].mnemonique)
#define ZJMP (op_tab[8].mnemonique)
#define STI (op_tab[10].mnemonique)
#define FORK (op_tab[11].mnemonique)
#define LFORK (op_tab[14].mnemonique)
#define BINARY_LENGTH (8)
#define SKIP_HEADER (2)
#define CUT_REG_DIR_SIZE (1)
#define TRUE (0)
#define FALSE (1)
#define REVERSE_SHORT(n) ((unsigned short) (((n & 0xFF) << 8) | \
                                            ((n & 0xFF00) >> 8)))
#define REVERSE_LONG(n) ((unsigned long) (((n & 0xFF) << 24) | \
                                            ((n & 0xFF00) << 8) | \
                                            ((n & 0xFF0000) >> 8) | \
                                            ((n & 0xFF000000) >> 24)))
typedef struct data_s {
    char **cmd;
    int *bytcode;
    int *type;
    int size;
}data_t;

enum data_type {
    REGISTER,
    INDIRECT,
    DIRECT,
    LABEL_INIT,
    LABEL_CALL_I,
    LABEL_CALL_D,
    INSTRUCTION,
    NAME_INIT,
    NAME_CONTENT,
    COMMENT_INIT,
    COMMENT_CONTENT
};

data_t **init_data(char **file);
data_t **create_data(char **file);
int *init_data_bytcode(data_t *data_arr);
data_t **init_data_instruction_bytcode(data_t **data_arr);
int *init_instruction_bytcode(void);
char **init_instruction_name(void);
data_t **init_parameters_bytcode(data_t **data_arr);
data_t **init_type(data_t **data_arr);
data_t **init_size(data_t **data_arr);
int count_size_file(char **data);
int count_size_line(char *str);
char *calcul_param_description(data_t *data);
int calcul_header_size(data_t **data_arr);
void write_file(data_t **data_arr, int fd);
void write_command(data_t **data_arr, int fd);
void write_header(data_t **data_arr, int fd);
int write_instruction_code(char *cmd, int fd);
void write_param_description(char const *binary_param, int fd);
void write_param_value(data_t **data_arr, int idx, int fd);
int check_special_cmd(char *cmd);
int calcul_len(char **cmd);
int calcul_label_range(data_t **data_arr, int idx, char *name);
int check_label_before(data_t **data_arr, int idx, char *name);
int check_label_after(data_t **data_arr, int idx, char *name);
void free_data_arr(data_t **data_arr);
int calcul_label_nb(data_t **data_arr);
char **init_label_array(data_t **data_arr);
#endif /* !DATA_H_ */
