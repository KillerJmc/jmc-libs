# capitalize(src result_str)
function(capitalize src result_str)
    # get first char
    string(SUBSTRING "${src}" 0 1 first_char)
    # first char to upper
    string(TOUPPER "${first_char}" first_char)
    # get substring
    string(SUBSTRING "${src}" 1 -1 rest)
    # join and set result_str
    set("${result_str}" "${first_char}${rest}" PARENT_SCOPE)
endfunction()

# hyphen_to_camel_case(src result_str)
function(hyphen_to_camel_case src result_str)
    # replace "-" to ";"
    string(REGEX REPLACE "-" ";" words "${src}")

    # capitalize words list
    set(capitalized_words)

    foreach(word IN LISTS words)
        # capitalize each word
        capitalize("${word}" word)
        # add to list
        list(APPEND capitalized_words "${word}")
    endforeach()

    # join list
    string(JOIN " " capitalized_string "${capitalized_words}")
    # remove ";"
    string(REGEX REPLACE ";" "" capitalized_string "${capitalized_string}")
       
    # set result
    set("${result_str}" "${capitalized_string}" PARENT_SCOPE)
endfunction()