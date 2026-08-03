#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Stable C++ identifier helpers for generated LeetCode classes."""


def class_name_from_slug(slug: str) -> str:
    """Convert a problem slug to a valid C++ class-name base."""
    name = "".join(word.capitalize() for word in slug.split("-") if word)
    if not name:
        return "Problem"
    if name[0].isdigit():
        return f"Problem{name}"
    return name
