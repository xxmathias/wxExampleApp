# name

`name` description

# Screenshots


# Dependecies

In order to compile and run `name`, you will need the following dependencies:

Ensure you have the wxWidgets library installed, along with its development headers.


```sh
sudo apt-get install libwxgtk3.0-dev
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

Navigate to the project's directory and create build and switch there:

```sh
cd name
mkdir build
cd build
```
Compile the application with make:

```sh
cmake ..
cmake --build .
```
# How to launch

In the build directory of the project:

```
./name
```
# DONE! 
## Testing with Catch2

Got Catch2? Sweet! Every time you mess with the classes we're testing, `name` runs its tests. So if you break something, we'll know. 🚀

## Clean Builds

Old build files hanging around? Ditch 'em. Clean builds = less weird bugs. It's like spring cleaning, but for your code. 🧹


=======
```sh
./unit_test
```

# License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

