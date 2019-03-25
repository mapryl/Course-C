#ifndef STREAM_H
# define STREAM_H

typedef struct s_stream {
	char* str;
	int lines;
	int size;
	int capacity;
} t_stream;

extern t_stream *g_output_stream;

void stream_init(t_stream *stream);
void stream_free(t_stream *stream);
void stream_put(t_stream* stream, char c);
int stream_compare(t_stream *stream1, t_stream *stream2);

#endif