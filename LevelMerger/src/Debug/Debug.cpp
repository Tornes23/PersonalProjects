/*!**************************************************************************
\file    ../debug.cpp

\author  Nestor Uriarte 

\par     DP email:  nestor.uriarte@digipen.edu 

\par     Course:    CS350 

\par     assignemnt 0 

\date    Mon Sep 21 17:16:04 2020

\brief	 This file containsm the implementation of the 
debug draw features

The functions included are:
- void debug_draw_point(glm::vec3 pt, glm::vec4 color);
- void debug_draw_points(std::shared_ptr<mesh> const& mesh, glm::mat4 const& m2w, glm::vec4 color);
- void debug_draw_segment(segment const& s, glm::vec4 color);
- void debug_draw_segments(std::shared_ptr<mesh> const& mesh, glm::mat4 const& m2w, glm::vec4 color);
- void debug_draw_triangle(triangle const& t, glm::vec4 color);
- void debug_draw_plane(glm::vec3 pt, glm::vec3 n, glm::vec4 color, float scale);
- void debug_draw_aabb(aabb const& a, glm::vec4 color);
- void debug_draw_sphere(sphere const& s, glm::vec4 color);
- void debug_draw_sphere_discs(sphere const& s, glm::vec4 color);
- void debug_draw_frustum(frustum const& s, glm::vec4 color);
- void debug_draw_fancy(std::shared_ptr<mesh> const& mesh, glm::mat4 const& m2w, glm::vec4 color, bool wire);
- void debug_draw_plain_color(std::shared_ptr<mesh> const& mesh, glm::mat4 const& m2w, glm::vec4 const& color, unsigned mode);
- void openglCallbackFunction(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

***************************************************************************/

#include "pch.hpp"
#include "debug.hpp"
#include "opengl.hpp"

namespace glm
{
    std::istream &operator>>(std::istream &is, vec2 &v)
    {
        is >> v.x >> v.y;
        return is;
    }

    std::ostream &operator<<(std::ostream &os, vec2 const &p)
    {
        os << p.x << " " << p.y;
        return os;
    }

    std::istream &operator>>(std::istream &is, vec3 &v)
    {
        is >> v.x >> v.y >> v.z;
        return is;
    }

    std::ostream &operator<<(std::ostream &os, vec3 const &p)
    {
        os << p.x << " " << p.y << " " << p.z;
        return os;
    }
} // namespace glm

/**************************************************************************
*!
\fn     openglCallbackFunction
\brief
The debug callback function
\param  GLenum source
the source of the error
\param  GLenum type
the error type
\param  GLuint id
the error id
\param  GLenum severity
the severity
\param  GLsizei length
\param  const GLchar* message
\param  const void* userParam
*
**************************************************************************/
void openglCallbackFunction(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
    //if is an error
    if (type == GL_DEBUG_TYPE_ERROR)
    {
        std::string _type = "ERROR";
        std::string _severity;
        //add the severity
        switch (severity)
        {
        case GL_DEBUG_SEVERITY_HIGH:
            _severity = "HIGH";
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            _severity = "MEDIUM";
            break;
        case GL_DEBUG_SEVERITY_LOW:
            _severity = "LOW";
            break;
        default:
            _severity = "UNKNOWN";
            break;
        }
        //print the error
        printf("%d: %s of %s severity, raised because: %s\n",
               id, _type.c_str(), _severity.c_str(), message);
        //abort after the print
        assert(type != GL_DEBUG_TYPE_ERROR);
    }
}
