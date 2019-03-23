#include "stdlib.h"
#include "utils.h"
#include "stream.h"

t_stream *g_output_stream;

void stream_init(t_stream *stream)
{
	int stream_initial_capacity;

	stream_initial_capacity = 10;
	stream->str = (char*)malloc(stream_initial_capacity * sizeof(char));
	*(stream->str) = '\0';
	stream->capacity = stream_initial_capacity;
	stream->size = 0;
	stream->lines = 0;
}

void stream_free(t_stream *stream)
{
	free(stream->str);
	stream->str = 0;
	stream->lines = 0;
	stream->size = 0;
	stream->capacity = 0;
}

void stream_put(t_stream* stream, char c)
{
	int stream_additional_chunk = 256;
	if (stream->size + 2 > stream->capacity)
	{
		stream->capacity += stream_additional_chunk;
		char* new_str = (char*)malloc(stream->capacity * sizeof(char));

		ft_strncpy(new_str, stream->str, stream->size);
		free(stream->str);
		stream->str = new_str;
	}
	stream->size += 1;
	stream->str[stream->size - 1] = c;
	stream->str[stream->size] = '\0';
	if (c == '\n')
		stream->lines++;
}

int stream_compare(t_stream *stream1, t_stream *stream2)
{
	return ft_strcmp(stream1->str, stream2->str);
}