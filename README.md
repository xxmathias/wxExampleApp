# name

`name` description

# Screenshots


# Dependecies

In order to compile and run `name`, you will need the following dependencies:

Ensure you have the wxWidgets library installed, along with its development headers.


```sh
sudo apt-get install wx2.8-headers libwxgtk2.8-0 libwxgtk2.8-dev
```

Ensure you have a C++ compiler. If using g++:

```sh
sudo apt-get install g++
```
# How to compile

Clone this repository to your local machine:

```sh
git clone 
```

Navigate to the project's directory:

```sh
cd name
```
Compile the application with make:

```sh
make
```
# How to launch

In the root directory of the project:

```
./name
```

# How to run unit tests

In the root directory of the project:

```sh 
mkdir build && cd build
```

```sh
cmake ..
```

```sh
make
```

```sh
./unit_test
```

# License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

