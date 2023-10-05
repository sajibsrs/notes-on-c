#include <stdio.h>
#include <time.h>

// Function to determine the time of day
char *day_division_name(int hour);

// Function to format the time as a string
char *format_time_string(char *time_string, int max_size, const struct tm *time);

int main(int argc, char *argv[])
{
    char time_string[64];
    struct tm *clock;
    time_t now;
    int hour;

    // Get the current time
    time(&now);
    clock = localtime(&now);
    hour = clock->tm_hour;

    // Greet the user based on the time of day
    printf("Good %s", day_division_name(hour));

    // Check for a command-line argument (user's name)
    if (argc < 2) {
        puts(", Stranger!");
    } else {
        printf(", %s!\n", argv[1]);
    }

    // Display the formatted time
    printf("%s", format_time_string(time_string, sizeof(time_string), clock));

    return 0;
}

// Determine the time of day based on the hour
char *day_division_name(int hour)
{
    char *name = NULL;

    if (hour >= 6 && hour < 12) {
        name = "morning";
    } else if (hour >= 12 && hour < 18) {
        name = "afternoon";
    } else if (hour >= 18 && hour < 24) {
        name = "evening";
    } else {
        name = "night";
    }
    return name;
}

// Format the time as a string
char *format_time_string(char *time_string, int max_size, const struct tm *time)
{
    // Format the time string with specific components
    strftime(time_string, max_size, "Today is %A, %B %d, %Y%nIt is %I:%M:%S %p%n", time);
    return time_string;
}
