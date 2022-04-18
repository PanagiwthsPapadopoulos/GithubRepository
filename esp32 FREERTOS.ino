#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else 
static const BaseType_t app_cpu = 1;
#endif


static const int led_pin = 4;

void toggleLED(void *parameter)
{
  while(1) {
    digitalWrite(led_pin, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);

  //task to run forever
  xTaskCreatePinnedToCore(          //use xtaskcreate in vanilla freertos
                  toggleLED,        //function to be called
                  "Toggle LED",     //name of task
                  1024,             //stack size
                  NULL,             //parameter to pass to function
                  1,                //task priority
                  NULL,             //task handle (pointer)
                  app_cpu);         // run on one core for demo purposes (esp32 only)

}

void loop() {
  // put your main code here, to run repeatedly:

}
