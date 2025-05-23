# Compile all programs
gcc producer_consumer.c -o producer_consumer -lpthread
gcc reader_writer.c -o reader_writer -lpthread
gcc race_condition.c -o race_condition -lpthread

# Run the programs
./producer_consumer
./reader_writer
./race_condition
