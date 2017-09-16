#include <iostream>
#include <cstdlib>

#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace std;

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitContextVersion(2,0);
    glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(0, 0);
    glutCreateWindow("Nuevo OpenGL");

    GLenum glew_status = glewInit();
    if(glew_status != GLEW_OK){
        cout << "Error inicializando GLEW!" << endl;
        exit(EXIT_FAILURE);
    }

    if(!GLEW_VERSION_2_0){
        cout << "Su tajeta gráfica no soporta OpenGL 2.0" << endl;
        exit(EXIT_FAILURE);
    }

    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *vendor = glGetString(GL_VENDOR);
    const GLubyte *version = glGetString(GL_VERSION);
    const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    cout << "GL Vendor:" << vendor << endl;
    cout << "GL Renderer:" << renderer << endl;
    cout << "GL Version (string):" << version << endl;
    cout << "GL Version (integer):" << major << ", " << minor << endl;
    cout << "GLSL Version:" << glslVersion << endl;

    // GLint nExtensions;
    // glGetIntegerv(GL_NUM_EXTENSIONS, &nExtensions);

    // for(int i = 0; i < nExtensions; i++){
        // cout << glGetStringi(GL_EXTENSIONS, i) << endl;
    // }

    exit(EXIT_SUCCESS);
}
