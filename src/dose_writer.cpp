#include <dose_writer.hpp>

void
DoseWriter::write(std::ostream &output, const Individual &individual, unsigned int index)
{
    output << "\t" << individual.get_dose( index ); 
}

void
ProbWriter::write(std::ostream &output, const Individual &individual, unsigned int index)
{
    output << "\t" << individual.get_dose( 2 * index ) << "\t" << individual.get_dose( 2 * index + 1 );
}

std::auto_ptr<DoseWriter>
get_writer(const std::string &type)
{
    if( type == "dose" )
    {
        return std::auto_ptr<DoseWriter>( new DoseWriter( ) );
    }
    else if( type == "prob" )
    {
        return std::auto_ptr<DoseWriter>( new ProbWriter( ) );
    }
    else
    {
        return std::auto_ptr<DoseWriter>( );
    }
}
