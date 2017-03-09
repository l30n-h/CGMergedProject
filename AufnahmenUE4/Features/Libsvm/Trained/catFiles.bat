copy ..\Test\* features.test
copy ..\Training\* features.training
copy /b features.test+features.training  features.all
PAUSE