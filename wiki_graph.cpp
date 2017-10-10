#include "wiki_graph.hpp"

WikiGraph::~WikiGraph(){
    if (n_links > 0){
        delete[] titles;
        delete[] sizes;
        delete[] links;
        delete[] redirect;
        delete[] offset;
    }
}

void  WikiGraph::load_from_stream(std::istream &file)
{
    file >> n_pages >> n_links;

    titles = new std::string [n_pages];
    sizes = new int32_t [n_pages];
    links = new int32_t [n_links];
    redirect = new bool [n_pages];
    offset = new int32_t [n_pages + 1];

    int tmp_redir = 0;

    for(int i = 0; i < n_pages; i++) {
        file >> titles[i]
             >> sizes[i]
             >> redirect[i]
             >> tmp_redir;

        for(int j = 0; j < tmp_redir; j++) {
            file >> links[i+j];
        }
    }

    std::cout << utf16_to_utf8(L"Граф загружен") << std::endl;
}

int32_t  WikiGraph::get_number_of_links_from(int32_t id)
{
    //FIXIT
    return 0;
};

int32_t*  WikiGraph::get_links_from(int32_t id)
{
    //FIXIT
    return links;
};

int32_t  WikiGraph::get_id(std::string title)
{
    //FIXIT
    return 0;
};

int32_t  WikiGraph::get_number_of_pages()
{
    //FIXIT
    return 0;
};

bool  WikiGraph::is_redirect(int32_t id)
{
    //FIXIT
    return true;
};

std::string  WikiGraph::get_title(int32_t id)
{
    //FIXIT
    return "";
};

int32_t  WikiGraph::get_page_size(int32_t id)
{
    //FIXIT
    return 0;
};
