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
    offset[0] = 0;

    int tmp_redir = 0;
    int j = 0;
    for(int i = 0; i < n_pages; i++) {
        file >> titles[i]
             >> sizes[i]
             >> redirect[i]
             >> tmp_redir;
        offset[i+1] = offset[i] + tmp_redir;
        tmp_redir += j;
        while(j < tmp_redir) {
            file >> links[j];
            j++;
        }
    }

    std::cout << utf16_to_utf8(L"Граф загружен") << std::endl;
}

int32_t  WikiGraph::get_number_of_links_from(int32_t id)
{
    if(id < n_pages && id >= 0) {
        return offset[id+1]-offset[id];
    }
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
    if(id < 0 || id > n_pages) return false;
    return redirect[id];
};

std::string  WikiGraph::get_title(int32_t id)
{
    if(id < 0 || id > n_pages) return "";
    return titles[id];
};

int32_t  WikiGraph::get_page_size(int32_t id)
{
    if(id < 0 || id > n_pages) return 0;
    return sizes[id];
    return 0;
};
