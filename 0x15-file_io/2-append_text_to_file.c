#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: pointer to the name of the file.
 * @text_content:  string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         else the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int v, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	v = open(filename, O_WRONLY | O_APPEND);
	w = write(v, text_content, len);

	if (v == -1 || w == -1)
		return (-1);

	close(v);

	return (1);
}
