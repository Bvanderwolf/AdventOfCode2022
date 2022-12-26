using System;
using System.Collections.Generic;
using System.IO;

namespace Day1
{
    // Input: a sequence of characters
    //  - the goal is to find the number of characters counted after which a sequence of 4 different characters was found.
    // Output: the number of characters counted
    class Program
    {
        static int GetNumberOfMarker(string sequence)
        {
            HashSet<char> characters = new HashSet<char>();
            
            for (int i = 0; i < sequence.Length; i++)
            {
                characters.Clear();
                characters.Add(sequence[i]);
                for (int j = i - 1; j >= 0; j--)
                {
                    if (!characters.Add(sequence[j]))
                        break;
                    if (characters.Count == 4)
                        return (i + 1);
                }
            }

            return (0);
        }
        
        static void Main(string[] args)
        {
            string path = @"D:\Persoonlijk\AdventOfCode\2022\AdventOfCode2022\C#_AdventOfCode22\Day6\input.txt";
            string sequence = File.ReadAllText(path);
            int marker = GetNumberOfMarker(sequence);
            Console.WriteLine(marker.ToString());
        }
    }
}